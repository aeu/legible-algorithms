// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-


#include <vector>
#include <iostream>
#include <unordered_map>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here

void printValues(vector<int> &arr)
{
    for(auto current : arr )
    {
        std::cout << current << "  ";
    }
    std::cout << endl;
}

bool balancedSplitExists(vector<int>& arr)
{
    std::sort(arr.begin(),arr.end());


    int sum_of_all_values = 0;
    int right_sum = 0;
    int left_sum = 0;
    for(auto current : arr )
    {
        sum_of_all_values += current ;
    }

    for(int index=0;index<arr.size();index++)
    {
        left_sum += arr[index];
        right_sum = sum_of_all_values - left_sum;
        if( left_sum == right_sum )
        {
            if( arr[index] < arr[index+1] )
                return true;
        }
    }
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

int main(){
  // Testcase 1
  vector<int> arr_1{2, 1, 2, 5};
  bool expected_1 = true;
  bool output_1 = balancedSplitExists(arr_1); 
  check(expected_1, output_1); 
  
  // Testcase 2
  vector<int> arr_2{3, 6, 3, 4, 4};
  bool expected_2 = false;
  bool output_2 = balancedSplitExists(arr_2); 
  check(expected_2, output_2); 

  // Add your own test cases here
  
  return 0; 
}
