// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>


using namespace std;

using namespace std;

// Add any helper functions you may need here


struct Node {
  int data; 
  Node* left ; 
  Node* right; 
  Node() {
    data = 0; 
    left = NULL; 
    right = NULL; 
  }
  Node(int data) {
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};

// Add any helper functions you may need here

int number_of_visible_nodes = 0;


int dfs(Node *current_node, int depth)
{
    if( current_node == NULL )
        return 0;

    if(( current_node->left == NULL ) && ( current_node->right == NULL ))
    {
        number_of_visible_nodes = std::max( depth, number_of_visible_nodes );
    }

    dfs( current_node->left, depth + 1 );
    dfs( current_node->right, depth + 1 );

    return depth;
}

int visibleNodes(Node* root)
{
    if( root == NULL )
        return 0;

    dfs( root, 1 );
    return number_of_visible_nodes;
}





// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  Node* root_1 = new Node(8); 
  root_1->left = new Node(3); 
  root_1->right = new Node(10); 
  root_1->left->left = new Node(1); 
  root_1->left->right = new Node(6); 
  root_1->right->right = new Node(14); 
  root_1->left->right->left = new Node(4); 
  root_1->left->right->right = new Node(7); 
  root_1->right->right->left = new Node(13); 
  int expected_1 = 4;
  int output_1 = visibleNodes(root_1);
  check(expected_1, output_1);

  Node* root_2 = new Node(10); 
  root_2->left = new Node(8);
  root_2->right = new Node(15);
  root_2->left->left = new Node(4);
  root_2->left->left->right = new Node(5);
  root_2->left->left->right->right = new Node(6);
  root_2->right->left = new Node(14);
  root_2->right->right = new Node(16);
  int expected_2 = 5;
  int output_2 = visibleNodes(root_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
