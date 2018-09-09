#pragma once
#include "Node.h"


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
