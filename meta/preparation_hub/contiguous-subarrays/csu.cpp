

#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>

// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

std::vector<int> buildLeftStack(std::vector<int> &arr )
{
    std::stack<int> stack;
    std::vector<int> left_results(arr.size(),-1);
    
    for(int index=0;index<arr.size();index++)
    {
        int current = arr[index];
        while( ! stack.empty())
        {
            int top = stack.top();
            if( current > arr[top] )
                stack.pop();
            else
                break;
        }
        if( ! stack.empty() )
        {
            left_results[index] = stack.top();
        }
        stack.push(index);
    }
    return left_results;
}

std::vector<int> buildRightStack(std::vector<int> &arr)
{
    std::stack<int> stack;
    std::vector<int> right_results(arr.size(),-1);
    for(int index=arr.size()-1;index>=0;index--)
    {
        int current = arr[index];
        while( ! stack.empty() )
        {
            int top = stack.top();
            if( current > arr[top] )
                stack.pop();
            else
                break;
        }
        if( ! stack.empty() )
            right_results[index] = stack.top();

        stack.push(index);
    }
    return right_results;
}


vector <int> CountSubarrays(vector <int> arr) {
  // Write your code here
    std::vector<int> left_results = buildLeftStack(arr);
    std::vector<int> right_results = buildRightStack(arr);
    std::vector<int> retval;
    for(int index=0;index<arr.size();index++)
    {
        int array_count = 0;
        int left_greater_index = left_results[index];
        if( left_greater_index == -1 )
        {
            array_count += index + 1;
        }
        else
        {
            array_count += index - left_greater_index;
        }
        int right_greater_index = right_results[index];
        if( right_greater_index == -1 )
        {
            array_count += arr.size() - index;
        }
        else
        {
            array_count += right_greater_index - index;
        }
        array_count--;
        retval.push_back(array_count);
    }
    return retval;
}



// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
