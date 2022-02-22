#include <stdio.h>
#include <stdlib.h>
// Add any extra import statements you may need here


struct Node {
  int data; 
  struct Node* left ; 
  struct Node* right; 
};

struct Node* newNode(int data) { 
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
  newNode->data = data; 
  newNode->left = NULL; 
  newNode->right = NULL; 

  return(newNode); 
} 

// Add any helper functions you may need here


int countNodes(struct Node* current_node, int depth)
{
  int retval      = depth;
  int left_depth  = 0;
  int right_depth = 0;
  
  if( current_node->left != NULL )
  {
    left_depth = countNodes( current_node->left,depth+1 );
  }
  if( current_node->right != NULL )
  {
    right_depth = countNodes( current_node->right,depth+1 );
  }

  if( left_depth > retval )
    retval = left_depth;

  if( right_depth > retval )
    retval = right_depth;

  return retval;
}


int visibleNodes(struct Node* root) {
  // Write your code here
  int retval = 0;
  retval = countNodes(root,1);
  return retval;
}




// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  printf("[%d]", n);
}

int test_case_number = 1;

void check(int expected, int output) {
  int result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    printf("%s Test #%d\n", rightTick, test_case_number);
  }
  else {
    printf("%s Test #%d: Expected ", wrongTick, test_case_number);
    printInteger(expected); 
    printf(" Your output: ");
    printInteger(output);
    printf("\n");
  }
  test_case_number++;
}

int main() {

  struct Node* root_1 = newNode(8); 
  root_1->left = newNode(3); 
  root_1->right = newNode(10); 
  root_1->left->left = newNode(1); 
  root_1->left->right = newNode(6); 
  root_1->right->right = newNode(14); 
  root_1->left->right->left = newNode(4); 
  root_1->left->right->right = newNode(7); 
  root_1->right->right->left = newNode(13); 
  int expected_1 = 4;
  int output_1 = visibleNodes(root_1);
  check(expected_1, output_1);

  struct Node* root_2 = newNode(10); 
  root_2->left = newNode(8);
  root_2->right = newNode(15);
  root_2->left->left = newNode(4);
  root_2->left->left->right = newNode(5);
  root_2->left->left->right->right = newNode(6);
  root_2->right->left = newNode(14);
  root_2->right->right = newNode(16);
  int expected_2 = 5;
  int output_2 = visibleNodes(root_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
