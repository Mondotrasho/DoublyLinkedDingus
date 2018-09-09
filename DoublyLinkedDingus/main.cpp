
#include <iostream>
#include "DllTemplate.h"


int main()
{
	DllTemplate<int> myList;
	myList.pushBack(12);
	myList.pushBack(52);
	myList.pushBack(91);
	myList.pushBack(40);

	// print each number in the list
	auto node = myList.GetFirst();
	while (node != nullptr) {
		std::cout << node << std::endl;
		node = node->GetNext();
	}
	return 0;
}

