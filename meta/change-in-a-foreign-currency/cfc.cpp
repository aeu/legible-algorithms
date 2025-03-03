// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
#include <vector>
#include <iostream>
#include <unordered_map>
// Add any extra import statements you may need here


using namespace std;

// Add any helper functions you may need here


bool canGetExactChange(int targetMoney, vector<int>& denominations)
{
    std::vector<int> possibles(targetMoney+1,0);
    possibles[0] = 1;
    
    for(auto current_denom : denominations )
    {
        for(int index=0;index<possibles.size();index++)
        {
            if( possibles[index] == 1 )
            {
                int next_possible = index+current_denom;
                if( next_possible < possibles.size() )
                    possibles[index+current_denom] = 1;
            }
        }
    }
    return possibles[targetMoney] ? true : false;
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

int main(){
  // Testcase 1
  int target_1 = 94;
  vector<int> arr_1{5, 10, 25, 100, 200};
  bool expected_1 = false;
  bool output_1 = canGetExactChange(target_1, arr_1); 
  check(expected_1, output_1); 
  
  // Testcase 2
  int target_2 = 75;
  vector<int> arr_2{4, 17, 29};
  bool expected_2 = true;
  bool output_2 = canGetExactChange(target_2, arr_2); 
  check(expected_2, output_2); 

  // Add your own test cases here
  
  return 0; 
} 

