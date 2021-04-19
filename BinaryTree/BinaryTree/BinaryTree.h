#pragma once

template <typename T>
class BinaryTree {
public:

	int get_size() const{ return size; }

	bool search(T value) const;

	void remove(T value);

	BinaryTree();

	BinaryTree(const BinaryTree<T> &other);

	BinaryTree<T>& operator = (const BinaryTree<T>& other);

	void add(T value);

	void print_inorder() const{
		inorder(this->root);
	}

	void destroy_tree() {
		destroy(this->root);
	}

	~BinaryTree() {
		destroy_tree();	
	}


private:

	template <typename T>
	class Node {
	public:
		Node* r_leaf;
		Node* l_leaf;
		T data;

		Node(T data = T(), Node* l_leaf = nullptr, Node* r_leaf = nullptr) {
			this->data = data;
			this->l_leaf = l_leaf;
			this->r_leaf = r_leaf;
		}
	};

	void copy_help(Node<T>* root, const Node<T>* other);

	int size;
	Node<T>* root;

	void inorder(Node<T>* root) const{

		if (root == nullptr) { return; }
		inorder(root->l_leaf);
		std::cout << root->data << " ";
		inorder(root->r_leaf);

	}
	void destroy(Node<T>* root) {
		if (root != nullptr) {
			destroy(root->l_leaf);
			destroy(root->r_leaf);
			delete root;
			--size;
		}
	}
};


template <typename T>
BinaryTree<T>::BinaryTree()
{
	size = 0;
	root = nullptr;
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other)
{
	if (other.root == nullptr) {
		this->root = nullptr;
		return;
	}
	this->root = new Node<T>(other.root->data);
	copy_help(this->root, other.root);

}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other)
{

	if (this->root != nullptr) {
		destroy_tree();
	}

	this->size = other.size;

	if (other.root == nullptr) {
		this->root = nullptr;
	}
	else {
		this->root = new Node<T>(other.root->data);
		copy_help(this->root, other.root);		
	}
	return *this;

}

template<typename T>
void BinaryTree<T>::copy_help(Node<T>* root, const Node<T>* other)
{
	if (other->l_leaf != nullptr) {
		root->l_leaf = new Node<T>(other->l_leaf->data);
		copy_help(root->l_leaf, other->l_leaf);
	}
	if (other->r_leaf != nullptr) {
		root->r_leaf = new Node<T>(other->r_leaf->data);
		copy_help(root->r_leaf, other->r_leaf);
	}
}


template<typename T>
void BinaryTree<T>::add(T value)
{

	if (this->root == nullptr) {
		root = new Node<T>(value);
	}
	else {
		Node<T>* current = this->root;
		while (1)
			if (value > current->data && current->r_leaf == nullptr) {

				current->r_leaf = new Node<T>(value);
				break;
			}
			else if (value > current->data && current->r_leaf != nullptr) {
				current = current->r_leaf;
			}
			else if (value < current->data && current->l_leaf == nullptr) {
				current->l_leaf = new Node<T>(value);
				break;
			}
			else if (value < current->data && current->l_leaf != nullptr) {
				current = current->l_leaf;
			}
			else if (value == current->data) {
				return;
			}
	}


	++size;
}

template<typename T>
bool BinaryTree<T>::search(T value) const{

	if (root == nullptr) {
		return false;
	}

	Node<T>* current = this->root;

	while (current != nullptr) {
		if (current->data == value) {
			return true;
		}
		else if (value > current->data) {
			current = current->r_leaf;
			if (current != nullptr && current->data == value) {
				return true;
			}
		}
		else if (value < current->data) {
			current = current->l_leaf;
			if (current != nullptr && current->data == value) {
				return true;
			}
		}
	}
	return false;
}

template<typename T>
void BinaryTree<T>::remove(T value)
{
	if (root == nullptr) {
		return;
	}

	if (root->data == value && root->l_leaf != nullptr && root->r_leaf != nullptr) {
		Node<T>* current = root;

		Node<T>* ptr = root->r_leaf;
		while (ptr->l_leaf != nullptr) {
			ptr = ptr->l_leaf;
		}
		ptr->l_leaf = current->l_leaf;
		root = current->r_leaf;
		delete current;
		--size;
		return;
	}
	else if (root->data == value && root->l_leaf != nullptr && root->r_leaf == nullptr) {
		Node<T>* current = root;
		root = root->l_leaf;
		delete root;
		--size;
		return;
	}
	else if (root->data == value && root->l_leaf == nullptr) {
		Node<T>* current = root;
		root = root->r_leaf;
		delete current;
		--size;
		return;
	}

	Node<T>* current = root;
	Node<T>* prev = current;
	while (current != nullptr) {
		if (value > current->data && current->r_leaf != nullptr) {
			prev = current;
			current = current->r_leaf;
			if (current->data == value && current->l_leaf != nullptr && current->r_leaf != nullptr) {
				Node<T>* ptr = current->r_leaf;
				prev->r_leaf = current->r_leaf;
				while (ptr->l_leaf != nullptr) {
					ptr = ptr->l_leaf;
				}
				ptr->l_leaf = current->l_leaf;
				delete current;
				--size;
				return;
			}
			else if (current->data == value && current->l_leaf != nullptr && current->r_leaf == nullptr) {
				prev->r_leaf = current->l_leaf;
				delete current;
				--size;
				return;
			}
			else if (current->data == value && current->l_leaf == nullptr) {
				prev->r_leaf = current->r_leaf;
				delete current;
				--size;
				return;
			}
		}
		else if (value > current->data && current->r_leaf == nullptr) {
			return;
		}

		else if (value < current->data && current->l_leaf != nullptr) {
			prev = current;
			current = current->l_leaf;
			if (current->data == value && current->l_leaf != nullptr && current->r_leaf != nullptr) {
				Node<T>* ptr = current->r_leaf;
				prev->l_leaf = current->r_leaf;
				while (ptr->l_leaf != nullptr) {
					ptr = ptr->l_leaf;
				}
				ptr->l_leaf = current->l_leaf;
				delete current;
				--size;
				return;
			}
			else if (current->data == value && current->l_leaf != nullptr && current->r_leaf == nullptr) {
				prev->l_leaf = current->l_leaf;
				delete current;
				--size;
				return;
			}
			else if (current->data == value && current->l_leaf == nullptr) {
				prev->l_leaf = current->r_leaf;
				delete current;
				--size;
				return;
			}
		}
		else if (value < current->data && current->l_leaf == nullptr) {
			return;
		}
	}
}
