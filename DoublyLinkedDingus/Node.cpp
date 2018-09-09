

#include "Node.h"

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
