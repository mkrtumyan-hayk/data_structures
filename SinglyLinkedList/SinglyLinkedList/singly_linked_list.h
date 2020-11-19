#pragma once

template<typename T>
class SinglyLinkedList
{
public:
	SinglyLinkedList();

	~SinglyLinkedList();

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
		T data;
		Node(T data = T(), Node* p_next = nullptr) {
			this->data = data;
			this->p_next = p_next;
		}
	};

	int size;
	Node<T>* head;
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	size = 0;
	head = nullptr;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	clear();
}

template<typename T>
void SinglyLinkedList<T>::push_back(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->p_next != nullptr) {

			current = current->p_next;

		}
		current->p_next = new Node<T>(data);
	}
	++size;
}

template<typename T>
T& SinglyLinkedList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->p_next;
		++counter;
	}
}

template<typename T>
void SinglyLinkedList<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->p_next;

	delete temp;

	--size;

}

template<typename T>
void SinglyLinkedList<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template<typename T>
void SinglyLinkedList<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	++size;
}

template<typename T>
void SinglyLinkedList<T>::insert(T value, int index)
{

	if (index == 0) {
		push_front(value);
	}
	else {

		Node<T>* previous = head;
		for (int i = 0; i < index - 1; ++i) {
			previous = previous->p_next;
		}

		Node<T>* newNode = new Node<T>(value, previous->p_next);
		previous->p_next = newNode;

		++size;
	}
}

template<typename T>
void SinglyLinkedList<T>::remove_at(int index)
{
	Node<T>* previous = head;
	for (int i = 0; i < index - 1; ++i) {
		previous = previous->p_next;
	}

	Node<T>* toDelete = previous->p_next;
	previous->p_next = toDelete->p_next;

	delete toDelete;

	--size;
}

template<typename T>
void SinglyLinkedList<T>::pop_back()
{
	remove_at(size - 1);
}

template<typename T>
void SinglyLinkedList<T>::remove_item(T value) {

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