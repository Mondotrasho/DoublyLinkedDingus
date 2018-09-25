#pragma once
#include "Node.h"
#include <cassert>

template<class TYPE>
class TLinkedList
{
private:
	Node<TYPE>* m_first;
	Node<TYPE>* m_last;
	int m_count;
public:
	//con and des
	TLinkedList();
	~TLinkedList();
	TLinkedList(const TLinkedList<TYPE>& otherList);

	//operators
	TLinkedList<TYPE>& operator=(const TLinkedList<TYPE>& otherList);

	//various inserts
	void push_front(TYPE value);
	void push_back(TYPE value);
	void insert_before(Node<TYPE>*, TYPE value);
	void insert_after(Node<TYPE>*, TYPE value);
	void insert_beginning(TYPE value);
	void insert_end(TYPE value);

	//find
	Node<TYPE>* find(TYPE value);

	//removal
	void pop_front(); // – remove the first item​ return value
	void pop_back(); // – remove the last item​ return value
	void erase(Node<TYPE>*); // – remove the node from the list​
	void remove_all(TYPE value);// – erases all nodes where the value is equal​
	void remove(TYPE value);  //single
	bool is_empty() const { return m_count == 0; }
	void clear();

	//ways to iterate through / setters and getters
	TYPE& first() { return m_first->get_value(); } //returns the value of the first
	TYPE& last() { return m_last->get_value(); } // –  and last node
	Node<TYPE>* begin() { return m_first; } // – returns a Node or an iterator to the first node​
	Node<TYPE>* end() { return nullptr; } // – returns a Node of null or an iterator to 1 passed the last ite
	Node<TYPE>* begin() const { return m_first; }
	Node<TYPE>* end() const { return nullptr; }
	void set_last(Node<TYPE>* new_last) { m_last = new_last; }
	void set_first(Node<TYPE>* new_first) { m_first = new_first; }
	Node<TYPE>*& get_first() { return m_first; }
	Node<TYPE>*& get_last() { return m_last; }
	//overloads
	Node<TYPE>* get_first() const { return m_first; }
	Node<TYPE>* get_last() const { return m_last; }

	//Utility
	int get_count() const { return m_count; }
	void print();
};



template<class TYPE>
TLinkedList<TYPE>::TLinkedList()
{
	m_count = 0;
	m_first = nullptr;
	m_last = nullptr;
}

template<class TYPE>
TLinkedList<TYPE>::~TLinkedList()
{
	if (m_first == m_last)
	{
		std::cout << m_first << std::endl;
		if (m_first != nullptr) {
			delete m_first;
			m_first = NULL;
		}
		std::cout << m_first << std::endl;
 // 	std::cout << m_last << std::endl;
  //	if (m_last != nullptr) {
 // 		delete m_last;
 // 		m_last = NULL;
 // 	}
		std::cout << m_last << std::endl;
		return;
	}//check its not empty or 1 size

	Node<TYPE> * curr = m_first;
	while(curr != nullptr)
	{
		Node<TYPE>* next = curr->get_next();
		delete curr;
		curr = NULL;
		curr = next;
		if (curr != nullptr) {
			curr->set_prev(NULL);
		}
		}
	curr = NULL;
	std::cout << " destructor " << std::endl;
}

template <class TYPE>
TLinkedList<TYPE>::TLinkedList(const TLinkedList<TYPE>& other_list)
{
	m_last = nullptr;
	m_first = nullptr;
	m_count = 0;
	clear();

	if (other_list.get_first() != nullptr) {
		Node<TYPE>* curr_other = other_list.get_first();
		while (curr_other != nullptr)
		{
			this->insert_end(curr_other->get_value());
			curr_other = curr_other->get_next();
		}
	}
	std::cout << " constructor " << std::endl;
	print();
}
template <class TYPE>
void TLinkedList<TYPE>::insert_before(Node<TYPE>* beforeThis, TYPE value)
{
	//newNode.next  : = node
	Node<TYPE>* new_node = new Node<TYPE>(value);
	new_node->set_next(beforeThis);
	//	if node.prev == null
	if (beforeThis->get_prev() == nullptr) {
		m_count += 1;
		beforeThis->set_prev(new_node);
		this->set_first(new_node);
		//		newNode.prev : = null-- (not always necessary)
		//		TLinkedList.firstNode : = newNode
	}
	//	else
	else
	{
		m_count += 1;
		new_node->set_prev(beforeThis->get_prev());
		beforeThis->get_prev()->set_next(new_node);
		beforeThis->set_prev(new_node);
		new_node->set_next(beforeThis);
		//		newNode.prev : = node.prev
		//		node.prev.next : = newNode
		//		node.prev : = newNode
	}
	std::cout << " insert_before " << std::endl;
	this->print();
}


template <class TYPE>
void TLinkedList<TYPE>::insert_after(Node<TYPE>* after_this, TYPE value)
{
	//newNode.prev  : = node
	Node<TYPE>* new_node = new Node<TYPE>(value);

	new_node->set_prev(after_this);
	//	if node.next == null
	if (after_this->get_next() == nullptr) {
		m_count += 1;
		new_node->set_next(nullptr);
		after_this->set_next(new_node);
		this->set_last(new_node);
		//		newNode.next : = null-- (not always necessary)
		//		TLinkedList.lastNode : = newNode
	}
	//	else
	else
	{
		m_count += 1;
		new_node->set_next(after_this->get_next());
		after_this->get_next()->set_prev(new_node);
		after_this->set_next(new_node);
		new_node->set_prev(after_this);
		//		newNode.next : = node.next
		//		node.next.prev : = newNode
		//		node.next : = newNode
	}
	std::cout << " insert_after " << std::endl;
	this->print();
}

template <class TYPE>
void TLinkedList<TYPE>::insert_beginning(TYPE value)
{
	
	//if TLinkedList.firstNode == null
	if (this->get_first() == nullptr)
	{
		Node<TYPE>* new_node = new Node<TYPE>(value);
		m_count += 1;
		this->set_first(new_node);
		this->set_last(new_node);
		new_node->set_prev(nullptr);
		new_node->set_next(nullptr);
		//	TLinkedList.firstNode  : = newNode
		//	TLinkedList.lastNode : = newNode
		//	newNode.prev : = null
		//	newNode.next : = null
	}
	//else
	else
	{
		this->insert_before(this->get_first(), value);
	}
	std::cout << " insert_beginning " << std::endl;
	this->print();
}

template <class TYPE>
void TLinkedList<TYPE>::insert_end(TYPE value)
{
	//	if TLinkedList.lastNode == null
	if (this->get_last() == nullptr)
	{
		this->insert_beginning(value);
	}
	//	else
	else
	{
		this->insert_after(this->get_last(), value);
	}

}

template <class TYPE>
Node<TYPE>* TLinkedList<TYPE>::find(TYPE value)
{
	//node  := TLinkedList.firstNode
	auto node = this->get_first();
	//	while node ≠ null
	while (node != nullptr)
	{
		//		<do something with node.data>
		if (node->get_value() == value)
		{
			return node;
		}
		//		node : = node.next
		node = node->get_next();
	}

	return nullptr; // was not found
}

template <class TYPE>
void TLinkedList<TYPE>::pop_front()
{
	auto N = get_first();

	if (this->get_first()->get_next() != nullptr) {
		this->get_first()->get_next()->set_prev(this->get_first()->get_prev());
	}

	this->set_first(this->get_first()->get_next());
	
	std::cout << " popfront " << std::endl;
	this->print();

	delete N;
	N = NULL;
}

template <class TYPE>
void TLinkedList<TYPE>::pop_back()
{
	auto N = this->get_last();
	if (this->get_last()->get_prev() != nullptr) {
		this->get_last()->get_prev()->set_next(this->get_last()->get_next());
	}
	
	this->set_last(this->get_last()->get_prev());

	std::cout << " popback " << std::endl;
	this->print();

	delete N;
	N = NULL;
}
template <class TYPE>
void TLinkedList<TYPE>::remove_all(TYPE value)
{
	while(find(value) != nullptr)
	{
		remove(value);
	}
}
template <class TYPE>
void TLinkedList<TYPE>::remove(TYPE value)
{
	if (is_empty()) { return; }
	//function remove(DLLTemplate TLinkedList, Node node)
	Node<TYPE>* remove = this->find(value);//Node<TYPE>(value);
	if (remove == nullptr) { return; }// not present
	//	if node.prev == null
	if (remove->get_prev() == nullptr)
	{
		this->set_first(remove->get_next());
		
		//		TLinkedList.firstNode  : = node.next
	}
	//	else
	else
	{
		remove->get_prev()->set_next(remove->get_next());
		
		//		node.prev.next  : = node.next
	}

	//		if node.next == null
	if (remove->get_next() == nullptr)
	{
		this->set_last(remove->get_prev());
		
		//			TLinkedList.lastNode : = node.prev
	}
	//		else
	else
	{
		remove->get_next()->set_prev(remove->get_prev());

		//			node.next.prev : = node.prev
	}
	m_count -= 1;
	delete remove;
	remove = NULL;
	std::cout << " remove " << std::endl;
	this->print();
}

template <class TYPE>
TLinkedList<TYPE>& TLinkedList<TYPE>::operator=(const TLinkedList<TYPE>& other_list)
{
	if (this == &other_list)
		return *this;
	this->clear();
	if (other_list.get_first() != nullptr) {
		//todo mem leak? or handled by the destructors when the list is destroyed?
		Node<TYPE>* curr = nullptr;

		curr = other_list.get_first();
		this->insert_end(curr->get_value());

		if (curr->get_next() != nullptr) {
			while (curr->get_next() != nullptr)
			{
				curr = curr->get_next();
				this->insert_end(curr->get_value());
			}
		}
	}
	std::cout << " = operator " << std::endl;
	this->print();

	return *this;
}

template <class TYPE>
void TLinkedList<TYPE>::push_front(TYPE value)
{
	this->insert_beginning(value);
}

template <class TYPE>
void TLinkedList<TYPE>::push_back(TYPE value)
{
	this->insert_end(value);
}
template <class TYPE>
void TLinkedList<TYPE>::erase(Node<TYPE>* node)
{
	if (is_empty()) { return; }
	while (this->find(node->get_value()) != nullptr)
	{
		this->remove(node->get_value());
	}
	std::cout << " erase " << std::endl;
	this->print();
}

template <class TYPE>
void TLinkedList<TYPE>::clear()
{
	if (this->is_empty()) { return; }
	while (this->get_first() != nullptr)
	{
		pop_front();
	}
	this->set_last(nullptr);
	if (get_last() != nullptr || get_first() != nullptr)
	{
		assert(get_first() != nullptr);
	};

	std::cout << " clear " << std::endl;
	this->print();
}

template <class TYPE>
void TLinkedList<TYPE>::print()
{
	if (this->is_empty())
	{
		std::cout << " SHE EMPTY " << std::endl;
		return;
	}
	Node<TYPE>* curr = nullptr;

	if (this->get_first() == nullptr)
	{
		std::cout << std::endl;
		return;
	}
	if (m_first == nullptr) { return; }
	curr = this->get_first();
	if (m_first == nullptr) { return; }
	while (curr != nullptr)
	{
		
		std::cout << curr->get_value() << " " << std::endl;
		//uh oh
		if (curr->get_next() == nullptr) { break; }
		curr = curr->get_next();

	}

	std::cout << std::endl;
}
