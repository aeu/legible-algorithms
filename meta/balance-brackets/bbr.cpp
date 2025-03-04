// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>


using namespace std;


bool bracketsMatch(char left, char right)
{
    if(( left == '{' ) && ( right == '}' ))
        return true;

    if(( left == '[' ) && ( right == ']' ))
        return true;

    if(( left == '(' ) && ( right == ')' ))
        return true;
    return false;
}

bool isOpener(char c)
{
    if(( c == '{' ) || ( c == '[' ) || ( c == '(' ))
        return true;
    return false;
}

bool isBalanced(string s)
{
    if( s.length() == 0 )
        return false;
    
    std::stack<char> brackets;
    for(char current : s )
    {
        if( isOpener( current ) )
            brackets.push(current);
        else
        {
            // can't get a closer with nothing on the stack
            if( brackets.empty() )
                return false;
            
            char top = brackets.top();
            if( bracketsMatch( top, current ))
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if( brackets.empty() )
        return true;
    return false;
}













// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(bool expected, bool output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printf("%s", expected ? "true" : "false");
    cout << " Your output: ";
    printf("%s", output ? "true" : "false");
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "{[(])}";
  bool expected_1 = false;
  bool output_1 = isBalanced(s_1);
  check(expected_1, output_1);

  string s_2 = "{{[[(())]]}}";
  bool expected_2 = true;
  bool output_2 = isBalanced(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}


