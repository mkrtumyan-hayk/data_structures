#include <iostream>
#include "linked_stack.h"

int main() {
	linked_stack<int> stck;

	//add elements
	std::cout << "Add elements! " << std::endl;
	stck.push(345);
	stck.push(23);
	stck.push(44);
	stck.push(53);
	stck.push(24);
	stck.push(55);
	stck.push(92);
	stck.push(69);
	stck.push(200);

	std::cout << "Size of stack: " << stck.get_size() << std::endl;

	//remove top element
	stck.pop();
	std::cout << "\nremove top element! \n";
	std::cout << "Size of stack: " << stck.get_size() << std::endl;
	//remove top element
	stck.pop();
	std::cout << "\nremove top element! \n";
	std::cout << "Size of stack: " << stck.get_size() << std::endl;


	std::cout << "\nShowing elements with popping them out : " << std::endl;
	while (!stck.empty()) {
		std::cout << stck.top() << " ";
		stck.pop();
	}
	std::cout << "\nSize of stack: " << stck.get_size() << std::endl;

	//add elements
	std::cout << "\nAdd elements! " << std::endl;
	stck.push(345);
	stck.push(88);
	stck.push(44);
	stck.push(7);
	stck.push(24);
	std::cout << "Size of stack: " << stck.get_size() << std::endl;

	//deallocate stack
	std::cout << "\nDeallocate stack! \n";
	stck.deallocate();
	std::cout << "Size of stack: " << stck.get_size() << std::endl;







	return 0;
}
