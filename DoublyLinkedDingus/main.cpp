
#include <iostream>
#include "DllTemplate.h"


int main()
{
	DllTemplate<int> a;
	a.pushBack(12);
	a.pushBack(52);
	a.pushBack(91);
	a.pushBack(40);

	std::cout << a.GetLast()->GetValue() << " the last"<< std::endl;

	a.pushFront(23);

	//a.


	// print each number in the list
	auto node = a.GetFirst();
	while (node != nullptr) {
		std::cout << node->GetValue() << std::endl;
		node = node->GetNext();
	}
	system("sleep");
	return 0;
}

