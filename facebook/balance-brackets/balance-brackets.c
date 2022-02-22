#include <stdio.h>
#include <stdbool.h>
// Add any extra import statements you may need here


// Add any helper functions you may need here


bool isBalanced(char s[]) {
  // Write your code here
  bool retval = true;
  char *open_ptr = NULL; // NULL;&s[0];
  char temp;
  for(char *read_ptr = &s[0]; *read_ptr != '\0'; read_ptr++ )
  {
    temp = *read_ptr;
    switch(temp)
    {
    case '{':
    case '[':
    case '(':
      if( ! open_ptr )
        open_ptr = &s[0];
      else
        open_ptr++;
      break;

    case '}':
      if( *open_ptr != '{' )
      {
        retval = false;
      }
      open_ptr--;
      break;
    case ']':
      if( *open_ptr != '[' )
      {
        retval = false;
      }
      open_ptr--;
      break;
    case ')':
      if( *open_ptr != '(' )
      {
        retval = false;
      }
      open_ptr--;
    }
      if( retval == false )
        break;
      
  }
  
  return retval;
}













// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printCharArray(char arr[]) {
  printf("[\"");
  for (int i = 0; arr[i] != '\0'; i++) {
    printf("%c", arr[i]);
  }
  printf("\"]");
}

int test_case_number = 1;

void check(bool expected, bool output) {
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (expected == output) {
    printf("%s Test #%d\n", rightTick, test_case_number);
  }
  else {
    printf("%s Test #%d: Expected ", wrongTick, test_case_number);
    printf("%s", expected ? "true" : "false");
    printf(" Your output: ");
    printf("%s", output ? "true" : "false");
    printf("\n");
  }
  test_case_number++;
}

int main() {

  char s_1[] = "{[(])}";
  bool expected_1 = false;
  bool output_1 = isBalanced(s_1);
  check(expected_1, output_1);

  char s_2[] = "{{[[(())]]}}";
  bool expected_2 = true;
  bool output_2 = isBalanced(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
