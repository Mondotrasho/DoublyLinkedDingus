
#include <iostream>
#include "DllTemplate.h"


int main()
{
//	DllTemplate<int> a;
//	a.pushBack(12);
//	a.pushBack(52);
//	a.pushBack(91);
//	a.pushBack(40);
//	a.pushBack(40);
//	a.pushBack(40);
//	a.pushBack(40);
//	a.pushBack(52);
//	a.Print();
//	// print each number in the list
//	/*auto node = a.GetFirst();
//	while (node != nullptr) {
//		std::cout << node->GetValue() << std::endl;
//		node = node->GetNext();
//	}*/
//	std::cout << " #####################################" << std::endl << std::endl << std::endl;
//	a.pushFront(23);
//	a.pushBack(1000);
//	a.Print();
//	// print each number in the list
//	/*node = a.GetFirst();
//	while (node != nullptr) {
//		std::cout << node->GetValue() << std::endl;
//		node = node->GetNext();
//	}*/
//	std::cout << " #####################################" << std::endl << std::endl << std::endl;
//	/*std::cout << a.GetLast()->GetValue() << " the last" << std::endl;
//	auto b = a.popBack();
//	std::cout << a.GetLast()->GetValue() << " last after" << std::endl;
//	std::cout << a.GetFirst()->GetValue() << " the First" << std::endl;
//	auto c = a.popFront();
//	std::cout << a.GetFirst()->GetValue() << " first after" << std::endl;*/
//
//
//	a.erase(a.find(40));
//	std::cout << " #####################################" << std::endl << std::endl << std::endl;
//	// print each number in the list
//	a.Print();
//	//node = a.GetFirst();
//	/*while (node != nullptr) {
//		std::cout << node->GetValue() << std::endl;
//		node = node->GetNext();
//	}*/
//	std::cout << " #####################################" << std::endl << std::endl << std::endl;
//
//	a.clear();
//
//	std::cout << " #####################################" << std::endl << std::endl << std::endl;
//	
//	std::cout << " #####################################" << std::endl << std::endl << std::endl;
//
//
	
	DllTemplate<int> list1;
		for (int i = 0; i < 3; ++i)
			list1.pushBack(i);

		auto list2 = list1;
		list2.Print();

		DllTemplate<int> list3;
		for (int i = 0; i < 5; ++i)
			list3.pushFront(i);

		list2 = list3;
		list2.Print();
		//list2.sort();
		list3 = list2;
		list3.Print();
		list3 = list1;
		list3.Print();

		//DllTemplate<int> list4{ 1,3,5,7,9,11,13,15 };
		//list4.Print();

		//DllTemplate<int> list5(9, 37);
		//list5.Print();
	
	system("pause");
	return 0;
}

