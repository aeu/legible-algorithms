// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>

using namespace std;

// Add any helper functions you may need here

typedef struct {
    std::vector<int> state;
    int num_steps;
} SearchState;

void dumpVector(std::vector<int> arr )
{
    for(auto current : arr )
    {
        std::cout << current << "," ;
    }
    std::cout << std::endl;
}


int minOperations(vector <int> arr)
{
    std::vector<int> goal = arr;
    std::sort(goal.begin(), goal.end());

    std::set<std::vector<int>> visited_states;
    visited_states.insert( arr );

    std::queue<SearchState> search_states;

    SearchState start = { arr, 0 };
    search_states.push(start);
    
    while( ! search_states.empty() )
    {
        SearchState current_state = search_states.front();
        search_states.pop();

        if( current_state.state == goal )
            return current_state.num_steps;

        for(int left=0;left<arr.size()-1;left++)
        {
            for(int right=left+1;right<arr.size();right++)
            {
                std::vector<int> new_state = current_state.state;
                std::reverse(new_state.begin()+left,new_state.begin()+right+1);
                if( visited_states.find( new_state ) == visited_states.end() )
                {
                    visited_states.insert( new_state );
                    SearchState next_search_state = { new_state, current_state.num_steps+1 };
                    search_states.push( next_search_state );
                }
            }
        }
    }
    return -1;
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

  int n_1 = 5;
  vector <int> arr_1{1, 2, 5, 4, 3};
  int expected_1 = 1;
  int output_1 = minOperations(arr_1);
  check(expected_1, output_1);

  int n_2 = 3;
  vector <int> arr_2{3, 1, 2};
  int expected_2 = 2;
  int output_2 = minOperations(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
