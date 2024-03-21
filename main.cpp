#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include <fstream>
using namespace std;

void add(Node*& node, int value);
void remove(Node*& node, int value);
bool search(Node* node, int value);
void print(Node* node, int count);

int main() {
    Node* root = nullptr;
    bool running = true;
    char command[50];
    char input[50];
    char cf;
    int numOfNums;
    int value;
    int temp;
    
    while(running == true){
      cout << "Please enter a command: ADD, DELETE, SEARCH, PRINT, or QUIT" << endl;
      cin.get(command, 50);
      cin.get();
      if(strcmp(command, "ADD") == 0){
	cout << "Would you like to enter in the console (c) or by a file (f)?" << endl;
	cin >> cf;
	cin.get();
	if(cf == 'c'){
	  cout << "How many numbers are you adding?" << endl;
	  cin >> numOfNums;
	  cin.get();
	  cout << "Enter your numbers: " << endl;
	  for (int i = 0; i < numOfNums; i++){
	    cin >> temp;
	    cin.get();
	    add(root, temp);
	  }
	}
	else if(cf == 'f'){
	  vector<int> numbers;
	  fstream first_stream;
	  first_stream.open("numbers.txt");
	  int number;
	  while(first_stream >> number){
	    numbers.push_back(number);
	  }
	  vector <int> ::iterator iter = numbers.begin();
	  for (iter = numbers.begin(); iter < numbers.end(); iter++){
	    add(root, *iter);
	  }
	}
      }
      else if(strcmp(command, "DELETE") == 0){
	cout << "Which value would you like to delete?" << endl;
	cin >> value;
	cin.get();
	remove(root, value);
      }
      else if(strcmp(command, "SEARCH") == 0){
	cout << "What value would you like to search for?" << endl;
	cin >> value;
	cin.get();
	if(search(root, value) == true){
	  cout << "This value exists..." << endl;
	}
	else if(search(root, value) == false){
	  cout << "This value does not exist..." << endl;
	}
      }
      else if(strcmp(command, "QUIT") == 0){
	cout << "Goodbye..." << endl;
	running = false;
      }
      else if(strcmp(command, "PRINT") == 0){
	print(root, 0);
      }
    }
    
    return 0;
}

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
