#pragma once

template<class TYPE>
class Node
{
private:
	Node<TYPE>* m_next;
	Node<TYPE>* m_prev;
	TYPE m_value;
public:

	explicit Node(TYPE value);
	Node();
	~Node();
	//Setters
	void set_value(TYPE value){ m_value = value; };
	void set_next(Node<TYPE>* next){ m_next = next; };
	void set_prev(Node<TYPE>* prev){	m_prev = prev;};
	//Getters
	TYPE get_value() { return m_value; };
	Node<TYPE>* get_next()const { return m_next; };
	Node<TYPE>*& get_next() { return m_next; };
	Node<TYPE>* get_prev()const { return m_prev; };
	Node<TYPE>*& get_prev() { return m_prev; };
};


template<class TYPE>
Node<TYPE>::Node()
{
	m_value = 0;
	m_next = nullptr;
	m_prev = nullptr;
}
template<class TYPE>
Node<TYPE>::Node(TYPE value)
{
	m_value = value;
	m_next = nullptr;
	m_prev = nullptr;
}
template<class TYPE>
Node<TYPE>::~Node()
{
	if (m_next != nullptr)
	{
		m_next =nullptr;
		//m_next = NULL;
	}
	if (m_prev != nullptr)
	{
		m_prev = nullptr;
		//m_prev = NULL;
	}
}
