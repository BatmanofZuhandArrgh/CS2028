// Data Structures Laboratory
// Section 004
// Lab 7
// 11/6/2019
// Group 6
// Group Members: Anh Nguyen and Michael Stephens


#include <iostream>

using namespace std;

template<class T>
class BinaryTree {
public:
    struct TreeNode {
        T value;
        TreeNode* left;
        TreeNode* right;
        
    };
    
    TreeNode* root;
    void insert(TreeNode*&, TreeNode*&);
    void destroySubTree(TreeNode*);
    void deleteNode(T, TreeNode*&);
    void makeDeletion(TreeNode*&);
    
    void displayInOrder(TreeNode*);
    void displayPreOrder(TreeNode*);
    void displayPostOrder(TreeNode*);
    
public:
    BinaryTree() {
        root = nullptr;
    }
    ~BinaryTree() {
        destroySubTree(root);
    }
    void insertNode(T);
    bool searchNode(T);
    void remove(T);
    
    void displaylab8() {
        outputTree(root, 0);
    }
    
    void displayInOrder() {
        displayInOrder(root);
    }
    
    void displayPreOrder() {
        displayPreOrder(root);
    }
    void displayPostOrder() {
        displayPostOrder(root);
    }
    
    void outputTree(TreeNode*, int);
};

template <class T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode) {
    if (nodePtr == nullptr) {// Insert the node.
        nodePtr = newNode;
    }
    else if (newNode->value < nodePtr->value){
        insert(nodePtr->left, newNode);
    }// Search the left branch
    else{
        insert(nodePtr->right, newNode);// Search the right branch
    }
    
}

template <class T>void BinaryTree<T>::insertNode(T num) {
    TreeNode* newNode = nullptr;// Pointer to a new node.
    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;
    // Insert the node.
    insert(root, newNode);
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode* nodePtr) {
    if (nodePtr->left) {
        destroySubTree(nodePtr->left);
    }
    if (nodePtr->right) {
        destroySubTree(nodePtr->right);
    }
    delete nodePtr;
}

//Determine if the value is present in tree
template <class T>
bool BinaryTree<T>::searchNode(T num) {
    bool status = false;
    TreeNode* nodePtr = root;
    while (nodePtr) {
        if (nodePtr->value == num) {
            status = true;
        }
        else if (num < nodePtr->value) {
            nodePtr = nodePtr->left;
        }
        else {
            nodePtr = nodePtr->right;
        }
    }return status;
}

template <class T>
void BinaryTree<T>::remove(T num) {
    deleteNode(num, root);
}

template <class T>
void BinaryTree<T>::deleteNode(T num, TreeNode*& nodePtr) {
    if (num < nodePtr->value) {
        deleteNode(num, nodePtr->left);
    }
    else if (num > nodePtr->value) {
        deleteNode(num, nodePtr->right);
    }
    else {
        makeDeletion(nodePtr);
    }
}

template<class T>
void BinaryTree<T>::makeDeletion(TreeNode*& nodePtr) {
    TreeNode* tempNodePtr = nullptr;
    if (nodePtr == nullptr) {
        cout << "Cannot delete empty node.\n";
    }
    else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr){
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach the right child
        delete tempNodePtr;
    }
    else {
        // Move one node the right.
        tempNodePtr = nodePtr->right;// Go to the end left node.
        while (tempNodePtr->left){
            tempNodePtr = tempNodePtr->left;
        }// Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;// Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode* nodePtr) {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
    
}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode* nodePtr) {
    if (nodePtr) {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode* nodePtr) {
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

template<class T>
void BinaryTree<T>::outputTree(TreeNode* NodePtr, int num) {
        
        while(NodePtr){
            outputTree(NodePtr->right, num + 5);
            for (int i = 1; i < num; i++){
                cout << " ";
            }
            cout << NodePtr->value;
            cout << endl;
            NodePtr = NodePtr->left;
            num = num+5;
        }
}


int main()
{
    BinaryTree<int> tree;
    //int TotalSpaces = 0;
    //cout << "Inserting nodes\n";
    tree.insertNode(49);
    tree.insertNode(28);
    tree.insertNode(83);
    tree.insertNode(18);
    tree.insertNode(40);
    tree.insertNode(71);
    tree.insertNode(97);
    tree.insertNode(11);
    tree.insertNode(19);
    tree.insertNode(32);
    tree.insertNode(44);
    tree.insertNode(69);
    tree.insertNode(72);
    tree.insertNode(92);
    
    tree.insertNode(99);
    
    tree.displaylab8();
    return 420;
}
