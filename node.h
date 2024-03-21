#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val);
    ~Node();
};

/*
void add(Node*& node, int value);
void remove(Node*& node, int value);
bool search(Node* node, int value);
void print(Node* node, int count);
*/

#endif // NODE_H
