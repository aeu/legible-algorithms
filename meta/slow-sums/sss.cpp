#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here


int getTotalTime(vector <int> arr) {
  // Write your code here
    std::priority_queue<int> max_heap;
    for( auto current : arr )
    {
        max_heap.push(current);
    }
    int penalty = 0;
    while( max_heap.size() > 1 )
    {
        int biggest = max_heap.top();
        max_heap.pop();
        int next_biggest = max_heap.top();
        max_heap.pop();
        int sum = biggest + next_biggest;
        max_heap.push( sum );
        penalty+=sum;
    }
    return penalty;
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

  vector <int> arr_1{4, 2, 1, 3};
  int expected_1 = 26;
  int output_1 = getTotalTime(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 3, 9, 8, 4};
  int expected_2 = 88;
  int output_2 = getTotalTime(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
