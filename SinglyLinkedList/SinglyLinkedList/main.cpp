#include <iostream>
#include "singly_linked_list.h"

int main() {
	
	SinglyLinkedList<int> lst;

	//add elements
	lst.push_back(72);
	lst.push_back(3);
	lst.push_back(456);
	lst.push_back(46);
	lst.push_back(98);
	lst.push_back(21);
	lst.push_back(40);
	lst.push_back(4);
	lst.push_back(699);

	std::cout << "Size of list: " << lst.get_size() << std::endl;
	std::cout << "Elements in list : " << std::endl;
	for (int i = 0; i < lst.get_size(); ++i) {
		std::cout << lst[i] << " ";
	}

	std::cout << "\n\nAdd an element to the beginning of the list : \n";
	lst.push_front(999);
	std::cout << "Size of list: " << lst.get_size() << std::endl;
	for (int i = 0; i < lst.get_size(); ++i) {
		std::cout << lst[i] << " ";
	}

	std::cout << "\n\nAdd an element in the fourth place : " << std::endl;
	lst.insert(222, 3);
	std::cout << "Size of list: " << lst.get_size() << std::endl;
	for (int i = 0; i < lst.get_size(); ++i) {
		std::cout << lst[i] << " ";
	}

	std::cout << "\n\nRemove element from sixth place : " << std::endl;
	lst.remove_at(5);
	std::cout << "Size of list: " << lst.get_size() << std::endl;
	for (int i = 0; i < lst.get_size(); ++i) {
		std::cout << lst[i] << " ";
	}

	std::cout << "\n\nRemove the last element of the list : " << std::endl;
	lst.pop_back();
	std::cout << "Size of list: " << lst.get_size() << std::endl;
	for (int i = 0; i < lst.get_size(); ++i) {
		std::cout << lst[i] << " ";
	}

	std::cout << "\n\nRemove the first element of the list : " << std::endl;
	lst.pop_front();
	std::cout << "Size of list: " << lst.get_size() << std::endl;
	for (int i = 0; i < lst.get_size(); ++i) {
		std::cout << lst[i] << " ";
	}

	std::cout << "\n\nRemove element by value: 40" << std::endl;
	lst.remove_item(40);
	std::cout << "Size of list: " << lst.get_size() << std::endl;
	for (int i = 0; i < lst.get_size(); ++i) {
		std::cout << lst[i] << " ";
	}
	
	std::cout << "\n\nRemove all elements of list : " << std::endl;
	lst.clear();
	std::cout << "Size of list: " << lst.get_size() << std::endl;

	return 0;
}
