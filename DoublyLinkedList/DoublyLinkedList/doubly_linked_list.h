#pragma once

template<typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();

	~DoublyLinkedList();

	int get_size() {
		return size;
	}

	void push_back(T data);

	T& operator[](const int index);

	void pop_front();

	void clear();

	void push_front(T data);

	void insert(T value, int index);

	void remove_at(int index);

	void pop_back();

	void remove_item(T value);

private:
	template<typename T>
	class Node {
	public:
		Node* p_next;
		Node* p_prev;
		T data;
		Node(T data = T(), Node* p_next = nullptr, Node* p_prev = nullptr) {
			this->data = data;
			this->p_next = p_next;
			this->p_prev = p_prev;
		}
	};

	int size;
	Node<T>* head;
	Node<T>* tail;
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size = 0;
	tail = head = nullptr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template<typename T>
void DoublyLinkedList<T>::push_back(T data)
{
	if (head == nullptr) {
		tail = head = new Node<T>(data);
		head->p_next = tail;
		head->p_prev = tail->p_prev = nullptr;
		tail->p_next = nullptr;
	}
	else {
		tail->p_next = new Node<T>(data);
		tail->p_next->p_prev = tail;
		tail = tail->p_next;

 	}
	++size;
}

template<typename T>
T& DoublyLinkedList<T>::operator[](const int index)
{
	int counter = 0;
	if (index <= size / 2) {
		Node<T>* current = this->head;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->p_next;
			++counter;
		}
	}
	else {
		counter = size-1;
		Node<T>* current = this->tail;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->p_prev;
			--counter;
		}
	}
}

template<typename T>
void DoublyLinkedList<T>::pop_front()
{
	Node<T>* temp = head;

	if (head->p_next != nullptr) {
		head = head->p_next;
		head->p_prev = nullptr;
		delete temp;
	} 
	else {
		delete tail;
		head = tail = nullptr;
	}

	--size;

}

template<typename T>
void DoublyLinkedList<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template<typename T>
void DoublyLinkedList<T>::push_front(T data)
{
	head = new Node<T>(data, head, nullptr);
	++size;
}

template<typename T>
void DoublyLinkedList<T>::remove_at(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = head;
		if (index < size / 2) {
			for (int i = 0; i < index - 1; ++i) {
				previous = previous->p_next;
			}
		}
		else {
			previous = tail;
			for (int i = size - 1; i > index - 1; --i) {
				previous = previous->p_prev;
			}
		}

		Node<T>* toDelete = previous->p_next;
		previous->p_next = toDelete->p_next;
		if (toDelete->p_next != nullptr) {
			toDelete->p_next->p_prev = previous;
		}
		else {
			tail = previous;
		}

		delete toDelete;
		--size;
	}
}

template<typename T>
void DoublyLinkedList<T>::pop_back()
{
	remove_at(size - 1);
}

template<typename T>
void DoublyLinkedList<T>::insert(T value, int index)
{

	if (index == 0) {
		push_front(value);
	}
	else if (index < size / 2) {		
		Node<T>* previous = head;
		for (int i = 0; i <  index-1; ++i) {
			previous = previous->p_next;
		}

		Node<T>* newNode = new Node<T>(value, previous->p_next, previous);
		previous->p_next = newNode;
		newNode->p_next->p_prev = newNode;
		++size;
	}
	else {
		Node<T>* previous = tail;
		for (int i = size-1; i > index - 1; --i) {
			previous = previous->p_prev;
		}
		Node<T>* newNode = new Node<T>(value, previous->p_next, previous);
		previous->p_next = newNode;
		if (newNode->p_next != nullptr) {
			newNode->p_next->p_prev = newNode;
		}
		else {
			tail = newNode;
		}
		++size;
	}
}

template<typename T>
void DoublyLinkedList<T>::remove_item(T value) {

	while (head != nullptr && head->data == value) {
		pop_front();
	}
	if (head == nullptr) {
		return;
	}

	Node<T>* previous = head;
	Node<T>* toDelete = previous->p_next;

	while (previous->p_next != nullptr) {
		if (toDelete->data == value) {

			toDelete = previous->p_next;
			previous->p_next = toDelete->p_next;
			if (previous->p_next != nullptr) {
				previous->p_next->p_prev = previous;
			}
			else {
				tail = previous;
			}
			delete toDelete;
			--size;
		}
		else {
			previous = previous->p_next;
			toDelete = previous->p_next;
		}
		toDelete = previous->p_next;
	}
}