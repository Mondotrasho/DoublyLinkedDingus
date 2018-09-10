#pragma once
#include "Node.h"
#include <cstddef>
#include <cassert>

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
	DllTemplate(const DllTemplate<TYPE>*& otherList);
	//DllTemplate<TYPE>(const DllTemplate<TYPE>& otherList);
	DllTemplate<TYPE> operator=(const DllTemplate<TYPE>* otherList);

	void pushFront(TYPE value); // – add the value to the beginning of the list​
	void pushBack(TYPE value); // – add the value to the end of the list​

	void insertbefore(Node<TYPE>*, TYPE value); // – insert a value before the node parameter​
	void insertafter(Node<TYPE>*, TYPE value);
	void insertbeginning(TYPE value);
	void insertEnd(TYPE value);
	Node<TYPE>* find(TYPE value);

	TYPE popFront(); // – remove the first item​ return value
	TYPE popBack(); // – remove the last item​ return value

	void erase(Node<TYPE>*); // – remove the node from the list​

	void remove(TYPE value); // – erases all nodes where the value is equal​


	//Common methods for accessing and iterating through nodes are
	TYPE& first() { return First->GetValue(); } //returns the value of the first
	TYPE& last() { return Last->GetValue(); } // –  and last node
	Node<TYPE>* begin() { return First; } // – returns a Node or an iterator to the first node​
	Node<TYPE>* end() { return nullptr; } // – returns a Node of null or an iterator to 1 passed the last ite
	Node<TYPE>* begin() const { return First; }
	Node<TYPE>* end() const { return nullptr; }
	
	void SetLast(Node<TYPE>* NewLast) { Last = NewLast; }
	void SetFirst(Node<TYPE>* NewFirst) { First = NewFirst; }
	Node<TYPE>*& GetFirst() { return First; }
	Node<TYPE>*& GetLast() { return Last; }
	Node<TYPE>* GetFirst() const { return First; }
	Node<TYPE>* GetLast() const { return Last; }

	int GetCount() const { return Count; }
	bool empty() { return First == nullptr; }
	void clear();

	void sort();
	int Move(int n);
	void Print();
};



template<class TYPE>
DllTemplate<TYPE>::DllTemplate()
{
	Count = 0;
	First = nullptr;
	Last = nullptr;
}

template<class TYPE>
DllTemplate<TYPE>::~DllTemplate()
{
	delete First;
	delete Last;
}

template <class TYPE>
DllTemplate<TYPE>::DllTemplate(const DllTemplate<TYPE>*& otherList)
{
	otherList = new DllTemplate<TYPE>;
	while (otherList.GetFirst()->GetNext() != nullptr)
	{
		Node<TYPE>* curr = otherList.GetFirst()->GetNext();
		insertEnd(curr->GetValue());
		otherList.GetFirst()->SetNext(curr->GetNext());
	}
}
//todo make inserts use the correct First and Last member varaibles
template <class TYPE>
void DllTemplate<TYPE>::insertbefore(Node<TYPE>* beforeThis, TYPE value)
{
	//newNode.next  : = node
	Node<TYPE>* New = new Node<TYPE>(value);
	New->SetNext(beforeThis);
	//	if node.prev == null
	if (beforeThis->GetPrev() == nullptr) {
		Count += 1;
		beforeThis->SetPrev(New);
		this->SetFirst(New);
		//		newNode.prev : = null-- (not always necessary)
		//		DllTemplate.firstNode : = newNode
	}
	//	else
	else
	{
		Count += 1;
		New->SetPrev(beforeThis->GetPrev());
		beforeThis->GetPrev()->SetNext(New);
		beforeThis->SetPrev(New);
		New->SetNext(beforeThis);
		//		newNode.prev : = node.prev
		//		node.prev.next : = newNode
		//		node.prev : = newNode
	}

}


template <class TYPE>
void DllTemplate<TYPE>::insertafter(Node<TYPE>* afterThis, TYPE value)
{
	//newNode.prev  : = node
	Node<TYPE>* New = new Node<TYPE>(value);
	
	New->SetPrev(afterThis);
	//	if node.next == null
	if (afterThis->GetNext() == nullptr) {
		Count += 1;
		New->SetNext(nullptr);
		afterThis->SetNext(New);
		this->SetLast(New);
		//		newNode.next : = null-- (not always necessary)
		//		DllTemplate.lastNode : = newNode
	}
	//	else
	else
	{
		Count += 1;
		New->SetNext(afterThis->GetNext());
		afterThis->GetNext()->SetPrev(New);
		afterThis->SetNext(New);
		New->SetPrev(afterThis);
		//		newNode.next : = node.next
		//		node.next.prev : = newNode
		//		node.next : = newNode
	}
}

template <class TYPE>
void DllTemplate<TYPE>::insertbeginning(TYPE value)
{
	Node<TYPE>* New = new Node<TYPE>(value);
	//if DllTemplate.firstNode == null
	if (this->GetFirst() == nullptr)
	{
		Count += 1;
		this->SetFirst(New);
		this->SetLast(New);
		New->SetPrev(nullptr);
		New->SetNext(nullptr);
		//	DllTemplate.firstNode  : = newNode
		//	DllTemplate.lastNode : = newNode
		//	newNode.prev : = null
		//	newNode.next : = null
	}
	//else
	else
	{
		this->insertbefore(this->GetFirst(), value);
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
TYPE DllTemplate<TYPE>::popFront()
{
	TYPE Temp = this->GetFirst()->GetValue();
	auto Newfirst = this->GetFirst()->GetNext();
	if (this->GetFirst()->GetNext() != nullptr) {
		this->GetFirst()->GetNext()->SetPrev(nullptr);
	}
	delete GetFirst();
	this->SetFirst(Newfirst);
	Count -= 1;
	if (GetFirst() == nullptr)
	{
		SetLast(nullptr);
	}
	return Temp;
}

template <class TYPE>
TYPE DllTemplate<TYPE>::popBack()
{
	TYPE Temp = this->GetLast()->GetValue();
	auto Newlast = this->GetLast()->GetPrev();
	if (this->GetFirst()->GetPrev() != nullptr) {
		this->GetLast()->GetPrev()->SetNext(nullptr);
	}
	delete GetLast();
	this->SetLast(Newlast);
	Count -= 1;
	if (GetLast() == nullptr)
	{
		SetFirst(nullptr);
	}
	return Temp;
}

template <class TYPE>
void DllTemplate<TYPE>::remove(TYPE value)
{
	if (empty()) { return; }
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
		Remove->GetNext()->SetPrev(Remove->GetPrev());
		//			node.next.prev : = node.prev
	}
}

template <class TYPE>
DllTemplate<TYPE> DllTemplate<TYPE>::operator=(const DllTemplate<TYPE>* otherList)
{
	if (this == &otherList)
		return *this;
	this->clear();
	while (otherList->GetFirst()->GetNext() != nullptr)
	{
		Node<TYPE>* curr = new Node<TYPE>;
		curr = otherList->GetFirst()->GetNext();
		this->insertEnd(curr->GetValue());
		otherList->GetFirst()->SetNext(curr->GetNext());
	}

	return *this;
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
template <class TYPE>
void DllTemplate<TYPE>::erase(Node<TYPE>* node)
{
	if (empty()) { return; }
	while(this->find(node->GetValue()) != nullptr)
	{
		this->remove(node->GetValue());
	}
}

template <class TYPE>
void DllTemplate<TYPE>::clear()
{
	if (empty()) { return; }
	while (this->GetFirst() != nullptr)
	{
		popFront();
	}
}

template <class TYPE>
void DllTemplate<TYPE>::sort()
{
	assert(nullptr);
}
template <class TYPE>
int DllTemplate<TYPE>::Move(int n)
{
	assert(nullptr);
}
template <class TYPE>
void DllTemplate<TYPE>::Print()
{
	if (empty()){return;}
	Node<TYPE>* curr = new Node<TYPE>;
	//Node<TYPE>* node = this->GetFirst();
	curr = this->GetFirst();
	while (curr->GetNext() != nullptr) 
	{
		std::cout << curr->GetValue() << " " << std::endl;//node->GetValue() <<" " << std::endl;
		curr = curr->GetNext();
	
	}
	std::cout << std::endl;
	return;
	assert(nullptr);
}