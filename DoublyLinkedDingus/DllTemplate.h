#pragma once
#include "Node.h"
#include <cstddef>

template<class TYPE>
class DllTemplate
{
private:
	Node<TYPE>* First;
	Node<TYPE>* Last;
	int Count;
public:
	DllTemplate();
	~DllTemplate();

	void pushFront(TYPE value); // – add the value to the beginning of the list​

	void pushBack(TYPE value); // – add the value to the end of the list​

	void insertbefore(Node<TYPE>*, TYPE value); // – insert a value before the node parameter​
	void insertafter(Node<TYPE>*, TYPE value);
	void insertbeginning(TYPE value);
	void insertEnd(TYPE value);
	Node<TYPE>* find(TYPE value);

	void popFront(); // – remove the first item​

	void popBack(); // – remove the last item​

	void erase(Node<TYPE>); // – remove the node from the list​

	void remove(TYPE value); // – erases all nodes where the value is equal​

							 //Common methods for accessing and iterating through nodes are
	TYPE& first() { return First->GetValue(); } //returns the value of the first
	TYPE& last() { return Last->GetValue(); } // –  and last node
	Node<TYPE>* begin() { return First; } // – returns a Node or an iterator to the first node​
	Node<TYPE>* end() { return nullptr; } // – returns a Node of null or an iterator to 1 passed the last ite
	void SetLast(Node<TYPE>* NewLast) { Last = NewLast; }
	void SetFirst(Node<TYPE>* NewFirst) { First = NewFirst; }
	Node<TYPE>*& GetFirst() { return First; }
	Node<TYPE>*& GetLast() { return Last; }
	Node<TYPE>* GetFirst() const { return First; }
	Node<TYPE>* GetLast() const { return Last; }


	void sort();
};



template<class TYPE>
DllTemplate<TYPE>::DllTemplate()
{
	Count = 0;
	First = NULL;
	Last = NULL;
}

template<class TYPE>
DllTemplate<TYPE>::~DllTemplate()
{
	delete First;
	delete Last;
}

template <class TYPE>
void DllTemplate<TYPE>::pushFront(TYPE value)
{
	this->insertbeginning(value);
}

template <class TYPE>
void DllTemplate<TYPE>::pushBack(TYPE value)
{
	this->insertEnd(value);
}
//todo make inserts use the correct First and Last member varaibles
template <class TYPE>
void DllTemplate<TYPE>::insertbefore(Node<TYPE>* beforeThis, TYPE value)
{
	//newNode.next  : = node
	Node<TYPE> New = Node<TYPE>(value);
	New.SetNext(&beforeThis);
	//	if node.prev == null
	if (beforeThis->GetNext() == NULL) {
		New.SetPrev(nullptr);
		this->SetFirst(&New);
		//		newNode.prev : = null-- (not always necessary)
		//		DllTemplate.firstNode : = newNode
	}
	//	else
	{
		New.SetPrev(beforeThis->GetPrev());
		beforeThis->GetPrev()->SetNext(&New);
		beforeThis->SetPrev(&New);
		//		newNode.prev : = node.prev
		//		node.prev.next : = newNode
		//		node.prev : = newNode
	}

}


template <class TYPE>
void DllTemplate<TYPE>::insertafter(Node<TYPE>* afterThis, TYPE value)
{
	//newNode.prev  : = node
	Node<TYPE> New = Node<TYPE>(value);
	New.SetPrev(&afterThis);
	//	if node.next == null
	if (afterThis->GetNext() == NULL) {
		New.SetNext(nullptr);
		this->SetLast(&New);
		//		newNode.next : = null-- (not always necessary)
		//		DllTemplate.lastNode : = newNode
	}
	//	else
	{
		New.SetNext(afterThis->GetNext());
		afterThis->GetNext()->SetPrev(&New);
		afterThis->SetNext(&New);
		//		newNode.next : = node.next
		//		node.next.prev : = newNode
		//		node.next : = newNode
	}
}

template <class TYPE>
void DllTemplate<TYPE>::insertbeginning(TYPE value)
{
	Node<TYPE> New = Node<TYPE>(value);
	//if DllTemplate.firstNode == null
	if (this->GetFirst() == nullptr)
	{
		this->SetFirst(&New);
		this->SetLast(&New);
		New.SetPrev(nullptr);
		New.SetNext(nullptr);
		//	DllTemplate.firstNode  : = newNode
		//	DllTemplate.lastNode : = newNode
		//	newNode.prev : = null
		//	newNode.next : = null
	}
	//else
	else
	{
		this->insertbefore(GetFirst(), value);
	}

}

template <class TYPE>
void DllTemplate<TYPE>::insertEnd(TYPE value)
{
	//	if DllTemplate.lastNode == null
	if (this->GetLast() == nullptr)
	{
		this->insertbeginning(value);
	}
	//	else
	else
	{
		this->insertafter(this->GetLast(), value);
	}

}

template <class TYPE>
Node<TYPE>* DllTemplate<TYPE>::find(TYPE value)
{
	//node  := DllTemplate.firstNode
	auto node = this->GetFirst();
	//	while node ≠ null
	while (node != nullptr)
	{
		//		<do something with node.data>
		if (node->GetValue() == value)
		{
			return node;
		}
		//		node : = node.next
		node = node->GetNext();
	}
	return nullptr; // was not found
}

template <class TYPE>
void DllTemplate<TYPE>::popFront()
{
	assert(nullptr);
}

template <class TYPE>
void DllTemplate<TYPE>::popBack()
{
	assert(nullptr);
}

template <class TYPE>
void DllTemplate<TYPE>::erase(Node<TYPE>)
{
	assert(nullptr);
}

template <class TYPE>
void DllTemplate<TYPE>::remove(TYPE value)
{
	//todo replace remove with find by value return pointer DONE I THINK
	//function remove(DLLTemplate DllTemplate, Node node)
	Node<TYPE>* Remove = this->find(value);//Node<TYPE>(value);
										   //	if node.prev == null
	if (Remove->GetPrev() == nullptr)
	{
		this->SetFirst(Remove->GetNext());
		//		DllTemplate.firstNode  : = node.next
	}
	//	else
	else
	{
		Remove->GetPrev()->SetNext(Remove->GetNext());
		//		node.prev.next  : = node.next
	}

	//		if node.next == null
	if (Remove->GetNext() == nullptr)
	{
		this->SetLast(Remove->GetPrev());
		//			DllTemplate.lastNode : = node.prev
	}
	//		else
	else
	{
		Remove->GetNext()->SetNext(Remove->GetPrev());
		//			node.next.prev : = node.prev
	}
}

template <class TYPE>
void DllTemplate<TYPE>::sort()
{
}

