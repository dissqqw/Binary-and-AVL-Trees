#include "AVL_treee.h" 
#include <iostream>
#include <string>

int main() {
    Binary_tree<int> bt;
    AVL_treee<int> avlTree;
    std::string expression;

    std::cout << "Enter the expression in parenthesis notation: ";
    std::getline(std::cin, expression); 

    try {
        Node<int>* binaryTreeRoot = bt.parseExpression(expression); 
        bt.preOrder(bt.root);

        if (binaryTreeRoot == nullptr) {
            std::cerr << "Error parsing expression." << std::endl;
            return 1;
        }


        /*std::cout << "\nTraversals of the AVL tree:" << std::endl;
        std::cout << "Breadth-first: ";
        avlTree.breadthFirstTraversal();
        std::cout << std::endl;

        std::cout << "Preorder: ";
        avlTree.preOrder(avlTree.root); 
        std::cout << std::endl;

        std::cout << "Inorder: ";
        avlTree.inOrder(avlTree.root);
        std::cout << std::endl;

        std::cout << "Postorder: ";
        avlTree.postOrder(avlTree.root); 
        std::cout << std::endl;*/

    }
    catch (const std::runtime_error& error) {
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }

    return 0;
}