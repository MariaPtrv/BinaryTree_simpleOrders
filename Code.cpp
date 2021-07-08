#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct tree_node {
    tree_node* left, * right;
    int value;
};

struct tree_node* add_node(int  v, tree_node* tree) {
    if (tree == NULL) {
        tree = new tree_node;
        tree->value = v;
        tree->left = NULL;
        tree->right = NULL;
    }
    else  if (v < tree->value)
        tree->left = add_node(v, tree->left);
    else
        tree->right = add_node(v, tree->right);
    return(tree);
}

struct tree_node* freeBinaryTree(tree_node* node) {
    if (node == NULL) return node;
    node->left = freeBinaryTree(node->left);
    node->right = freeBinaryTree(node->right);
    node = NULL;
    return node;
}


struct tree_node* addBinaryTree(tree_node* root) {
    string tree_str;
    std::cout << "\nВведите вершины дерева через пробел (Например, '1 2 3')\n";
    getline(cin, tree_str);
    getline(cin, tree_str);
    int temp;
    std::stringstream in(tree_str);
    while(in >> temp)
    {
        root = add_node(temp, root);
    }
    return root;
}

void preorderPrint(tree_node* node)
{
    if (node == NULL)  
    {
        return;
    }
    std::cout << node->value << " ";
    preorderPrint(node->left);   
    preorderPrint(node->right);  
}

void inorderPrint(tree_node* node)
{
    if (node == NULL)  
    {
        return;
    }
    preorderPrint(node->left);   
    std::cout << node->value << " ";
    preorderPrint(node->right); 
}

void postorderPrint(tree_node* node)
{
    if (node == NULL)
    {
        return;
    }
    preorderPrint(node->left);
    preorderPrint(node->right);  
    std::cout << node->value << " ";
}


void read_tree() {

}
void printBinaryTree(tree_node*  root) {
    std::cout <<  "\nПорядок обхода:\n1 - Прямой (Pre-order)\n\n";
    preorderPrint(root);
    std::cout << "\n2 - Центрированный (In-order)\n\n";
    inorderPrint(root);
    std::cout << "\n3 - Обратный (Post-order)\n\n";
    postorderPrint(root);
}


int main() {
    bool exit = false;
    int mode; 
    struct tree_node* root;
    root = NULL;
    while (!exit)
    {
        std::cout << "\nВыберите задачу:\n1 - Ввести бинарное дерево \n2 - Обойти бинарное дерево\n3 - Добавить узел дерева\n4 -  Удалить дерево\nЛюбая другая клавиша - Выйти\n";
        std::cin >> mode;
        switch (mode)
        {
        case 1:
            root = addBinaryTree(root);
            break;
        case 2:
            printBinaryTree(root);
            break;
        case 3:
            root = addBinaryTree(root);
            break;
        case 4:
            root = freeBinaryTree(root);
            break;
        default:
            exit = true;
            break;
        }
    }

    return 0;
}
