#include "node.h"
#include <iostream>
#include <cstring>
using namespace std;


Node::Node(int val){
  data = val;
  left = nullptr;
  right = nullptr;
}

Node::~Node(){
  
}
/*
void add(Node*& node, int value) {
    if (node == nullptr)
        node = new Node(value);
    else if (value < node->data)
        add(node->left, value);
    else if (value > node->data)
        add(node->right, value);
}

Node* findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void remove(Node*& node, int value) {
    if (node == nullptr)
        return;
    if (value < node->data)
        remove(node->left, value);
    else if (value > node->data)
        remove(node->right, value);
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

bool search(Node* node, int value) {
    if (node == nullptr)
        return false;
    if (node->data == value)
        return true;
    if (value < node->data)
        return search(node->left, value);
    else
        return search(node->right, value);
}

void print(Node* node, int count) {
    if(node == NULL){
      cout << "NOTHING IN THE TREE" << endl;
    return;
  }
  else if(node->right != NULL){
      print(node->right, count + 1);
    }
    
  for(int i = 0; i < count; i++){
        cout << '\t';
    }
    //prints
    cout << node->data << endl;
    
  if(node->left != NULL){
        print(node->left, count + 1);
    }
}
*/
