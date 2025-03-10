#include "AVL_treee.h"

template <typename T>
void AVL_treee<T>::deleteNodesRecursive(Node<T>* node) {
	if (node != nullptr) {
		deleteNodesRecursive(node->left);
		deleteNodesRecursive(node->right);
		delete node;
	}
}

template <typename T>
int AVL_treee<T>::height(Node<T>* node) {
	if (node == nullptr)
		return 0;
	return node->height;
}

template <typename T>

int AVL_treee<T>::getBalance(Node<T>* node) {
	if (node == nullptr) return 0;
	return height(node->left) - height(node->right);
}

template <typename T>

void AVL_treee<T>::TreeRotateR(Node<T>* node) {
	Node<T>* y = node->left;
	node->left = y->right;
	if (y->right != nullptr) {
		y->right->parent = node;
	}
	y->parent = node->parent;
	if (node->parent == nullptr) {
		root = y;
	}
	else if (node == node->parent->right) {
		node->parent->right = y;
	}
	else {
		node->parent->left = y;
	}
	y->right = node;
	node->parent = y;
	node->balance = getBalance(node);
	y->balance = getBalance(y);
}

template <typename T>

void AVL_treee<T>::TreeRotateL(Node<T>* node) {
	if (node == nullptr || node->right == nullptr) return;

	Node<T>* y = node->right;

	node->right = y->left;
	if (y->left != nullptr) {
		y->left->parent = node;
	}

	y->parent = node->parent;

	if (node->parent == nullptr) {
		root = y;
	}
	else if (node == node->parent->left) {
		node->parent->left = y;
	}
	else {
		node->parent->right = y;
	}

	y->left = node;
	node->parent = y;
	node->balance = getBalance(node);
	y->balance = getBalance(y);
}

template <typename T>

void AVL_treee<T>::TreeRotateLR(Node<T>* node) {
	TreeRotateL(node->left);
	TreeRotateR(node);
}

template<typename T>

void AVL_treee<T>::TreeRotateRL(Node<T>* node) {
	TreeRotateR(node->right);
	TreeRotateL(node);
}

template <typename T>

void AVL_treee<T>::AVL_RestoreBalance(Node<T>* node) {
	node->balance = getBalance(node);
	if (node->balance < -1) {
		if (height(node->left->left) > height(node->left->right)) {
			TreeRotateR(node);
		}
		else {
			TreeRotateLR(node);
		}
	}
	if (getBalance(node) > 1) {
		if (height(node->right->right) > height(node->right->left)) {
			TreeRotateL(node);
		}
		else {
			TreeRotateRL(node);
		}
	}
}

template <typename T>

void AVL_treee<T>::AVLInsert(Node<T>* node) {
	Node<T>* current = node;
	AVL_RestoreBalance(current);
	current = current->parent;
}

//template <typename T>
//void AVL_tree<T>::AVLDelete(Node<T>* node) {
//	Node<T>* deleted = TreeDelete(node);
//	Node<T>* current = deleted->parent;
//	while (current != nullptr) {
//		AVL_RestoreBalance(current);
//		current = current->parent;
//	}
//}
//
//template <typename T>
//void AVL_tree<T>::breadthFirstTraversal() {
//	if (root == nullptr) return;
//
//	std::queue<Node<T>*> q;
//	q.push(root);
//
//	while (!q.empty()) {
//		Node<T>* current = q.front();
//		q.pop();
//		std::cout << current->data << " ";
//
//		if (current->left) q.push(current->left);
//		if (current->right) q.push(current->right);
//	}
//	std::cout << std::endl;
//} 
//
//template <typename T>
//void AVL_tree<T>::inOrder(Node<T>* node) {
//	if (node == nullptr) return;
//	inOrder(node->left);
//	printf("%d ", node->data);
//	inOrder(node->right);
//}
//
//template <typename T>
//void AVL_tree<T>::postOrder(Node<T>* node) {
//	if (node == nullptr) return;
//	postOrder(node->left);
//	postOrder(node->right);
//	printf("%d ", node->data);
//}
//
//template <typename T>
//void AVL_tree<T>::preOrder(Node<T>* node) {
//	if (node == nullptr) return;
//	printf("%d ", node->data);
//	preOrder(node->left);
//	preOrder(node->right);
//}

