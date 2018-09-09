#pragma once

template<class TYPE>
class Node
{
private:
	Node<TYPE>* m_next;
	Node<TYPE>* m_prev;
	TYPE m_value;
public:
	
	Node(TYPE value);
	Node();
	~Node();
	//Setters
	void SetValue(TYPE value){ m_value = value; };
	void SetNext(Node<TYPE>* next){ m_next = next; };
	void SetPrev(Node<TYPE>* prev){	m_prev = prev;};
	//Getters
	TYPE GetValue() { return m_value; };
	Node<TYPE>* GetNext()const { return m_next; };
	Node<TYPE>*& GetNext() { return m_next; };
	Node<TYPE>* GetPrev()const { return m_prev; };
	Node<TYPE>*& GetPrev() { return m_prev; };
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
Node<TYPE>::~Node() = default;
