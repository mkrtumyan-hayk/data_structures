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
		Node *pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	
	int Size;
	Node<T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
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
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
		
			current = current->pNext;
		
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>*current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	
	head = head->pNext;
	
	delete temp;
	
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
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{

	if (index == 0) {
		push_front(value);
	}
	else {
		
		Node<T> *previous = head;
		for (int i = 0; i < index - 1; ++i) {
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List<T>::remove_at(int index)
 {
	Node<T>* previous = head;
	for (int i = 0; i < index - 1; ++i) {
		previous = previous->pNext;
	}

	Node<T>* toDelete = previous->pNext;
	previous->pNext = toDelete->pNext;

	delete toDelete;

	Size--;
}

template<typename T>
void List<T>::pop_back()
{
	remove_at(Size - 1);
}

template<typename T>
void List<T>::remove_item(T value) {
	while (head->data == value && head != nullptr) {
		Node<T>* ToDelete = head;;
		head = head->pNext;
		delete ToDelete;
		Size--;
	}
	if (head == nullptr) {
		return;
	}

	Node<int>* previous = head;
	Node<int>* toDelete = previous->pNext;

	while (previous->pNext != nullptr) {
		if (toDelete->data == value) {

			toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			Size--;
			continue;
		}
		previous = previous->pNext;
		toDelete = previous->pNext;

	}
}
