
#include <iostream>
#include "DllTemplate.h"


int main()
{
	DllTemplate<int> a;
	a.pushBack(12);
	a.pushBack(52);
	a.pushBack(91);
	a.pushBack(40);

	

	a.pushFront(23);
	std::cout << a.GetLast()->GetValue() << " the last" << std::endl;
	auto b = a.popBack();
	std::cout << a.GetLast()->GetValue() << " last after" << std::endl;
	std::cout << a.GetFirst()->GetValue() << " the First" << std::endl;
	auto c = a.popFront();
	std::cout << a.GetFirst()->GetValue() << " first after" << std::endl;

	// print each number in the list
	auto node = a.GetFirst();
	while (node != nullptr) {
		std::cout << node->GetValue() << std::endl;
		node = node->GetNext();
	}
	system("sleep");
	return 0;
}

