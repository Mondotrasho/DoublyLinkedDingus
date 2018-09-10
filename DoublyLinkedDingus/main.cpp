
#include <iostream>
#include "DllTemplate.h"


int main()
{
	DllTemplate<int> a;
	a.pushBack(12);
	a.pushBack(52);
	a.pushBack(91);
	a.pushBack(40);

	// print each number in the list
	auto node = a.GetFirst();
	while (node != nullptr) {
		std::cout << node->GetValue() << std::endl;
		node = node->GetNext();
	}
	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	a.pushFront(23);
	a.pushBack(1000);

	// print each number in the list
	node = a.GetFirst();
	while (node != nullptr) {
		std::cout << node->GetValue() << std::endl;
		node = node->GetNext();
	}
	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	std::cout << a.GetLast()->GetValue() << " the last" << std::endl;
	auto b = a.popBack();
	std::cout << a.GetLast()->GetValue() << " last after" << std::endl;
	std::cout << a.GetFirst()->GetValue() << " the First" << std::endl;
	auto c = a.popFront();
	std::cout << a.GetFirst()->GetValue() << " first after" << std::endl;
	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	// print each number in the list
	node = a.GetFirst();
	while (node != nullptr) {
		std::cout << node->GetValue() << std::endl;
		node = node->GetNext();
	}
	std::cout << " #####################################" << std::endl << std::endl << std::endl;

	a.clear();

	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	system("pause");
	return 0;
}

