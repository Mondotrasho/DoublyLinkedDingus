
#include <iostream>
#include "TLinkedList.h"

void FillRand(TLinkedList<int>& other,int with)
{
	for (int i = 0; i < with; ++i)
	{
		other.push_back(rand() % 300);
	}
}
int main()
{

	TLinkedList<int> testa;
	testa.push_back(123);
	testa.push_back(23);
	testa.push_back(1);
	testa.push_back(13);
	testa.push_back(31);
	srand(NULL);

	TLinkedList<int> test;
	FillRand(test, 100);
	auto Shouldbe100 = test.get_count();
	test.pop_back();
	auto Shouldbe99 = test.get_count();

	TLinkedList<int> all9s;
	for (int i = 0; i < 50; ++i)
	{
		all9s.push_back(9);
	}
	all9s.push_back(10); // add a ten 51 total
	all9s.remove(9); //remove the first 9 size 50
	all9s.remove_all(9); //remove the rest size 1

	



	TLinkedList<int> a;
	a.push_back(12);
	a.push_back(52);
	a.push_back(91);
	a.push_back(40);
	a.push_back(40);
	a.push_back(40);
	a.push_back(40);
	a.push_back(52);
	a.print();
	// print each number in the list
	auto node = a.get_first();
	while (node != nullptr) {
		std::cout << node->get_value() << std::endl;
		node = node->get_next();
	}
	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	a.push_front(23);
	a.push_back(1000);
	a.print();
	// print each number in the list
	node = a.get_first();
	while (node != nullptr) {
		std::cout << node->get_value() << std::endl;
		node = node->get_next();
	}
	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	std::cout << a.get_last()->get_value() << " the last" << std::endl;
	a.pop_back();
	std::cout << a.get_last()->get_value() << " last after" << std::endl;
	std::cout << a.get_first()->get_value() << " the First" << std::endl;
	a.pop_front();
	std::cout << a.get_first()->get_value() << " first after" << std::endl;


	a.erase(a.find(40));
	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	// print each number in the list
	a.print();
	node = a.get_first();
	while (node != nullptr) {
		std::cout << node->get_value() << std::endl;
		node = node->get_next();
}
	std::cout << " #####################################" << std::endl << std::endl << std::endl;

	a.clear();

	std::cout << " #####################################" << std::endl << std::endl << std::endl;
	
	std::cout << " #####################################" << std::endl << std::endl << std::endl;


	TLinkedList<int> list1;
	for (int i = 0; i < 3; ++i)
			list1.push_back(i);

		auto list2 = list1;
		list2.print();

		TLinkedList<int> list3;
		for (int i = 0; i < 5; ++i)
			list3.push_front(i);

		list2 = list3;
		list2.print();
		//list2.sort();
		list3 = list2;
		list3.print();
		list3 = list1;
		list3.print();
		auto listlist = list1;




		//TLinkedList<int> list4{ 1,3,5,7,9,11,13,15 };
		//list4.Print();

		//TLinkedList<int> list5(9, 37);
		//list5.Print();

	return 0;
}

