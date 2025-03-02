#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


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

int binarySearch(const int target, vector<int> values)
{
    int low = 0;
    int high = values.size()-1;
    int mid = low + (( high - low ) / 2 );
    while( low < high )
    {
        if( target <= values[mid] )
        {
            high = mid ;
        }
        else
        {
            low = mid+1 ;
        }
        mid = low + (( high - low ) / 2 );
    }
    if (low < values.size() && values[low] >= target)
        return low + 1;
    return -1;
}

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {

    std::vector<int> milestone_days (milestones.size(),-1);
    std::vector<int> precomputed_revenues;
    int revenue_to_date = 0;
    int milestone_index = 0;
    
    auto highest_milestone = std::max_element(milestones.begin(), milestones.end());
    int max_stone = *highest_milestone;
    for(int index=0;index<revenues.size();index++)
    {
        revenue_to_date += revenues[index];
        precomputed_revenues.push_back( revenue_to_date );
        if( revenue_to_date > max_stone )
            break;
    }

    for(int index=0;index<milestones.size();index++)
    {
        int current_milestone = milestones[index];
        int found = binarySearch( current_milestone, precomputed_revenues );
        milestone_days[index] = found;
    }
    return milestone_days;
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
  // Testcase 1
  int n_1 = 5, k_1 = 4; 
  vector <int> revenues_1{100, 200, 300, 400, 500};
  vector <int> milestones_1{300, 800, 1000, 1400};
  vector <int> expected_1{2, 4, 4, 5};
  vector <int> output_1 = getMilestoneDays(revenues_1, milestones_1);
  check(expected_1, output_1);

  // Testcase 2
  int n_2 = 6, k_2 = 5; 
  vector <int> revenues_2{700, 800, 600, 400, 600, 700};
  vector <int> milestones_2{3100, 2200, 800, 2100, 1000};
  vector <int> expected_2{5, 4, 2, 3, 2};
  vector <int> output_2 = getMilestoneDays(revenues_2, milestones_2);
  check(expected_2, output_2);
  
  // Add your own test cases here
  
}
