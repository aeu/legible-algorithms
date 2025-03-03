// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-


#include <vector>
#include <iostream>
#include <unordered_map>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here


string findEncryptedWord(string s)
{
    int N = s.length();
    
    if( N <= 2 )
        return s;

    int midpoint;
    if( N % 2 )
        midpoint = ( N / 2 ) + 1;
    else
        midpoint = N / 2;

    std::string left_chunk  = s.substr(0,midpoint-1);
    std::string right_chunk = s.substr(midpoint );
    std::string middle      = s.substr(midpoint-1,1);

    std::string retval = middle;
    retval += findEncryptedWord(left_chunk);
    retval += findEncryptedWord(right_chunk);

    return retval;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << " Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "abc";
  string expected_1 = "bac";
  string output_1 = findEncryptedWord(s_1);
  check(expected_1, output_1);
  {
  string s_2 = "abcd";
  string expected_2 = "bacd";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);
  }
  {
  string s_2 = "abcxcba";
  string expected_2 = "xbacbca";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);
  }
  {
  string s_2 = "facebook";
  string expected_2 = "eafcobok";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);
  }
  // Add your own test cases here
  
}

