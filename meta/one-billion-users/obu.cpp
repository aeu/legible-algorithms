#include <vector>
#include <iostream>
#include <unordered_map>


// Add any extra import statements you may need here

using namespace std;

// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

double getUserCount(std::vector<float> growthRates, int days )
{
    double user_count = 0;
    for(float current_rate : growthRates )
    {
        user_count += pow(current_rate,days);
    }
    return user_count;
}


int getBillionUsersDay(vector <float> growthRates) {
  // Write your code here
    double goal = 1000000000;
    double user_count = 0;
    int low = 1;
    int high = 1;
    user_count = getUserCount(growthRates,high);
    while( user_count < goal )
    {
        high *= 2;
        user_count = getUserCount(growthRates,high);
    }
    int mid;
    while( low < high )
    {
        mid = low + (( high - low ) / 2 );
        user_count = getUserCount(growthRates, mid );
        if( user_count > goal )
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    return high;
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

  vector <float> test_1{1.1, 1.2, 1.3};
  int expected_1 = 79;
  int output_1 = getBillionUsersDay(test_1);
  check(expected_1, output_1);

  vector <float> test_2{1.01, 1.02};
  int expected_2 = 1047;
  int output_2 = getBillionUsersDay(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
