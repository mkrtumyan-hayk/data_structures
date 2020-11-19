#include <iostream>
#include "BinaryTree.h"

int main() {

	BinaryTree<int> tree;

	//add elements
	tree.add(35);
	tree.add(27);
	tree.add(64);
	tree.add(15);
	tree.add(28);
	tree.add(50);
	tree.add(100);
	tree.add(69);
	tree.add(200);

	
	std::cout << "Size of tree: "<< tree.get_size() << std::endl;
	std::cout << "Elements in tree : " << std::endl;
	tree.print_inorder();
	std::cout << std::endl;

	//remove elements
	std::cout << "\nRemove elements!";
	tree.remove(27);
	tree.remove(15);
	tree.remove(28);
	tree.remove(64);
	tree.remove(100);

	std::cout << "\nSize of tree: " << tree.get_size() << std::endl;
	std::cout << "Elements in tree : " << std::endl;
	tree.print_inorder();
	std::cout << std::endl;

	//check if element exists in tree
	if (tree.search(27)) { std::cout << "\n27: exists in tree:)"; }
	else { std::cout << "\n27: is not found:("; }

	if (tree.search(69)) { std::cout << "\n69: exists in tree:)\n"; }
	else { std::cout << "\n69: is not in tree:(\n"; }

	//destroy tree
	std::cout << "\nDestroy tree!";
	tree.destroy_tree();

	std::cout << "\nSize of tree: " << tree.get_size() << std::endl;

	return 0;
}