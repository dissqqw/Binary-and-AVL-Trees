#include "Binary_tree.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename T>
void Binary_tree<T>::deleteNodesRecursive(Node<T>* node) {
	if (node != nullptr) {
		deleteNodesRecursive(node->left);
		deleteNodesRecursive(node->right);
		delete node;
	}
}


template <typename T>
void Binary_tree<T>::preOrder(Node<T>* node) {
	if (node == nullptr) return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

template <typename T>
Node<T>* Binary_tree<T>::parseExpression(const std::string& input) {
	std::stack<Node<T>*> nodeStack;
	std::istringstream stream(input);
	char ch;

	while (stream >> ch) {
		if (ch == '(') {
			T value;
			stream >> value;
			Node<T>* node = new Node<T>;
			node->data = value;
			if (!nodeStack.empty()) {
				if (nodeStack.top()->left == nullptr) {
					nodeStack.top()->left = node;
				}
				else {
					nodeStack.top()->right = node;
				}
			}
			else {
				root = node;
			}
			nodeStack.push(node);
		}
		else if (ch == ')') {
			nodeStack.pop();
		}
	}
	return root;
}

template <typename T>

Node<T>* Binary_tree<T>::Search(T value) {
	Node<T>* x = root;
	while (x != nullptr && x->data != value) {
		if (x->data > value) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	return x;
}

template <typename T>

Node<T>* Binary_tree<T>::TreeMin(Node<T>* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

template <typename T>

Node<T>* Binary_tree<T>::TreeMax(Node<T>* node) {
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

template <typename T>

Node<T>* Binary_tree<T>::TreeSuccessor(Node <T>* node) {
	if (node == nullptr) return nullptr;
	if (node->right != nullptr) {
		return TreeMin(node->right);
	}
	Node<T>* y = node->parent;
	while (y != nullptr && node == y->right) {
		node = y;
		y = y->parent;
	}
	return y;
}

template <typename T>

Node<T>* Binary_tree<T>::TreeSearchInexact(T value) {
	Node<T>* y = nullptr;
	Node <T>* x = root;
	while (x != nullptr && value != x->data) {
		y = x;
		if (value < x->data) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	if (x != nullptr) {
		y = x;
	}
	return y;
}

template <typename T>

void Binary_tree<T>::TreeInsert(Node<T>* node) {
	if (node == nullptr) {
		throw std::invalid_argument("Cannot insert a nullptr node");
	}
	Node <T>* y = TreeSearchInexact(node->data);
	node->parent = y;
	if (y == nullptr) {
		root = node;
	}
	else if (node->data < y->data) {
		y->left = node;
	}
	else {
		y->right = node;
	}
}

template <typename T>

void Binary_tree<T>::TreeDelete(Node<T>* nodeToDelete) {
	Node<T>* x;
	Node<T>* y;
	if (nodeToDelete == nullptr) {
		throw std::invalid_argument("Cannot insert a nullptr node");
	}
	if (nodeToDelete->left == nullptr || nodeToDelete->right == nullptr) {
		y = nodeToDelete;
	}
	else {
		y = TreeSuccessor(nodeToDelete);
	}
	if (y->left != nullptr) {
		x = y->left;
	}
	else {
		x = y->right;
	}
	if (x != nullptr) {
		x->parent = y->parent;
	}
	if (y->parent == nullptr) {
		root = x;
	}
	else if (y == y->parent->left) {
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}
	if (y != nodeToDelete) {
		nodeToDelete->data = y->data;
	}
	delete y;
}

template class Binary_tree<int>;
template class Node<int>;