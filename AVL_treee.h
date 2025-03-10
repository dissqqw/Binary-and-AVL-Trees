#pragma once
#include "Binary_tree.h"
#include <queue>

template <typename T>
class AVL_treee
{
public:
	Node<T>* root;
	int height(Node<T>* node);
	int getBalance(Node<T>* N);
	AVL_treee() : root(nullptr) {};
	~AVL_treee() { deleteNodesRecursive(root); }
	void deleteNodesRecursive(Node<T>* node);
	void TreeRotateR(Node<T>* node);
	void TreeRotateL(Node<T>* node);
	void TreeRotateLR(Node<T>* node);
	void TreeRotateRL(Node<T>* node);
	void AVL_RestoreBalance(Node<T>* node);
	void AVLInsert(Node<T>* node);
	/*void preorder(node<t>* node);
	void avldelete(node<t>* node);
	void breadthfirsttraversal();
	void inorder(node<t>* node);
	void postorder(node<t>* node);*/
};

