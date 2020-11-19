#pragma once

template<typename T>
class linked_stack {
public:

	void push(const T&);

	void pop();

	int get_size() const { return size; }

	bool empty() const { return size == 0; }

	T& top();

	void deallocate();

	linked_stack();

	~linked_stack();

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
	int size;

};

template<typename T>
void linked_stack<T>::push(const T& value)
{
	Node<T>* current = new Node<T>(value);
	current->prev = m_top;
	m_top = current;
	++size;
}

template<typename T>
void linked_stack<T>::pop()
{
	if (m_top != nullptr) {
		Node<T>* toDelete = m_top;
		m_top = m_top->prev;
		delete toDelete;
		--size;
	}
}

template<typename T>
linked_stack<T>::linked_stack()
{
	size = 0;
	m_top = nullptr;
}

template<typename T>
T& linked_stack<T>::top()
{
	return m_top->data;
}

template<typename T>
void linked_stack<T>::deallocate()
{
	while (m_top != nullptr)
	{
		Node<T>* toDelete = m_top;
		m_top = m_top->prev;
		delete toDelete;
		size = 0;
	}
}

template<typename T>
linked_stack<T>::~linked_stack()
{
	deallocate();
}