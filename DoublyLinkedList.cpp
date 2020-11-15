#include <iostream>


template<typename T>
class List
{
public:
	List();

	~List();

	int GetSize() {
		return Size;
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
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};

	int Size;
	Node<T>* head;
	Node<T>* tail;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	tail = head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) {
		tail = head = new Node<T>(data);
		head->pNext = tail;
		head->pPrev = tail->pPrev = nullptr;
		tail->pNext = nullptr;
	}
	else {
		tail->pNext = new Node<T>(data);
		tail->pNext->pPrev = tail;
		tail = tail->pNext;

 	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	if (index <= Size / 2) {
		Node<T>* current = this->head;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pNext;
			++counter;
		}
	}
	else {
		counter = Size-1;
		Node<T>* current = this->tail;
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pPrev;
			--counter;
		}
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	if (head->pNext != nullptr) {
		head = head->pNext;
		head->pPrev = nullptr;
		delete temp;
	} 
	else {
		delete tail;
		head = tail = nullptr;
	}

	Size--;

}

template<typename T>
void List<T>::clear()
{
	while (Size) {
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head, nullptr);
	Size++;
}

template<typename T>
void List<T>::remove_at(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = head;
		if (index < Size / 2) {
			for (int i = 0; i < index - 1; ++i) {
				previous = previous->pNext;
			}
		}
		else {
			previous = tail;
			for (int i = Size - 1; i > index - 1; --i) {
				previous = previous->pPrev;
			}
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		if (toDelete->pNext != nullptr) {
			toDelete->pNext->pPrev = previous;
		}
		else {
			tail = previous;
		}

		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	remove_at(Size - 1);
}

template<typename T>
void List<T>::insert(T value, int index)
{

	if (index == 0) {
		push_front(value);
	}
	else if (index < Size / 2) {		
		Node<T>* previous = head;
		for (int i = 0; i <  index-1; ++i) {
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(value, previous->pNext, previous);
		previous->pNext = newNode;
		newNode->pNext->pPrev = newNode;
		++Size;
	}
	else {
		Node<T>* previous = tail;
		for (int i = Size-1; i > index - 1; --i) {
			previous = previous->pPrev;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext, previous);
		previous->pNext = newNode;
		if (newNode->pNext != nullptr) {
			newNode->pNext->pPrev = newNode;
		}
		else {
			tail = newNode;
		}
		++Size;
	}
}

template<typename T>
void List<T>::remove_item(T value) {

	while (head != nullptr && head->data == value) {
		pop_front();
	}
	if (head == nullptr) {
		return;
	}

	Node<T>* previous = head;
	Node<T>* toDelete = previous->pNext;

	while (previous->pNext != nullptr) {
		if (toDelete->data == value) {

			toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			if (previous->pNext != nullptr) {
				previous->pNext->pPrev = previous;
			}
			else {
				tail = previous;
			}
			delete toDelete;
			--Size;
		}
		else {
			previous = previous->pNext;
			toDelete = previous->pNext;
		}
		toDelete = previous->pNext;
	}
}