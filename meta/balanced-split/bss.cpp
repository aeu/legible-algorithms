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
    std::vector<int> left_sums;
    std::vector<int> right_sums;
    int N = arr.size();
    std::cout << "arr ";
    printValues(arr);
    int left_sum = 0;
    for(auto current : arr )
    {
        left_sum += current;
        left_sums.push_back(left_sum);
    }
    std::cout << "left_sums ";
    printValues(left_sums);
    int right_sum = 0;
    for(int index=arr.size()-1;index>=0;index--)
    {
        int current = arr[index];
        right_sum += current;
        right_sums.push_back( right_sum);
    }
    //    std::sort(right_sums.begin(),right_sums.end());
    std::cout << "right_sums as is ";
    printValues(right_sums);

    for(int index=0;index<arr.size()-1;index++)
    {
        std::cout << "comparing " << left_sums[index] << " and " << right_sums[N-index-1] << std::endl;
        if( left_sums[index] == right_sums[N-index] )
        {
            cout << "passes the first" << std::endl;
            if( arr[index] <= arr[index+1] )
            {
                std::cout << "compared " << arr[index] << " and " << arr[index+1] << std::endl; 
                return true;
            }
            else
            {
            }
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
