#include <stdio.h>
#include <iostream>

// Method 2: Using "class" to make
// user-define data type
class Node {
public:
    int data;
    Node* left;
    Node* right;

 Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }

};

class BinaryTree {
 public:
  Node* root;
 
  BinaryTree() {
    root = nullptr;
  }
 
  void addNode(int data) {
    Node* newNode = new Node(data);
 
    if (root == nullptr) {
      root = newNode;
    } else {
      Node* focusNode = root;
      Node* parent;
 
      while (true) {
        parent = focusNode;
 
        if (data < focusNode->data) {
          focusNode = focusNode->left;
          if (focusNode == nullptr) {
            parent->left = newNode;
            return;
          }
        } else {
          focusNode = focusNode->right;
          if (focusNode == nullptr) {
            parent->right = newNode;
            return;
          }
        }
      }
    }
  }
 
  void preOrderTraversal(Node* focusNode) {
    if (focusNode != nullptr) {
      std::cout << focusNode->data << " ";
      preOrderTraversal(focusNode->left);
      preOrderTraversal(focusNode->right);
    }
  }
};


int main(){

  BinaryTree t1;
  t1.addNode(45);
  t1.addNode(34);
  t1.addNode(12);
  t1.addNode(72);
  t1.addNode(72);
  t1.addNode(71);

  t1.preOrderTraversal(t1.root);
   

    return 0;
}