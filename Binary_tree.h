#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <iomanip>

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node* parent;
    Node(T value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {} 
    Node() : data(T{}), left(nullptr), right(nullptr), parent(nullptr) {} 
    ~Node() { delete left; delete right; delete parent; }
};

template <typename T>
class Binary_tree {

public:
    Node<T>* root;
    void deleteNodesRecursive(Node<T>* node);
    Binary_tree() : root(nullptr) {};
    ~Binary_tree() { deleteNodesRecursive(root); };
    Node<T>* parseExpression(const std::string& input);
    void preOrder(Node<T>* node);
    Node<T>* Search(T value);
    Node<T>* TreeMin(Node<T>* node);
    Node<T>* TreeMax(Node<T>* node);
    Node<T>* TreeSuccessor(Node<T>* node);
    Node<T>* TreeSearchInexact(T value);
    void TreeInsert(Node<T>* node);
    void TreeDelete(Node<T>* nodeToDelete);
};

#endif // BINARY_TREE_H