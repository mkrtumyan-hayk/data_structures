#include <iostream>

template<typename T>
class LinkedStack {
public:

	void push(const T&);

	void pop();

	int GetSize() const {	return Size; }

	bool empty() const { return Size == 0; }

	T& top();

	void deallocate();

	LinkedStack();

	~LinkedStack();

private:

	template<typename T>
	class Node {
	public:
		Node* prev;
		T data;
		Node(T data = T(), Node* prev = nullptr) {
			this->data = data;
			this->prev = prev;
		}
	};

	Node<T>* m_top;
	int Size;

};

template<typename T>
void LinkedStack<T>::push(const T& value)
{
	Node<T>* current = new Node<T>(value);
	current->prev = m_top;
	m_top = current;
	++Size;
}

template<typename T>
void LinkedStack<T>::pop()
{
	if (m_top != nullptr) {
		Node<T>* toDelete = m_top;
		m_top = m_top->prev;
		delete toDelete;
		--Size;
	}
}

template<typename T>
LinkedStack<T>::LinkedStack()
{
	Size = 0; 
	m_top = nullptr;
}

template<typename T>
T& LinkedStack<T>::top()
{
	return m_top->data;
}

template<typename T>
void LinkedStack<T>::deallocate()
{
	while (m_top != nullptr) 
	{
		Node<T>* toDelete = m_top;
		m_top = m_top->prev;
		delete toDelete;
	}
}

template<typename T>
LinkedStack<T>::~LinkedStack()
{
	deallocate();
}