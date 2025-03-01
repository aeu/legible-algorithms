

#include <vector>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>

// Add any extra import statements you may need here

using namespace std;


int matchingPairs(string s, string t)
{
    int N = t.length();
    int matching_pair_count = 0;
    std::unordered_set<std::string> unmatched_pairs;
    std::map<char,int> schar_count;
    std::map<char,int> tchar_count;
    bool perfect_swap_exists = false;
    for(int index=0;index<N;index++)
    {
        schar_count[ s[index] ]++;
        tchar_count[ t[index] ]++;
        if( s[index] == t[index] )
            matching_pair_count++;
        else
        {
            std::string pair    = { s[index] , t[index] };
            std::string inverse = { t[index] , s[index] };
            unmatched_pairs.insert( pair );
            if( ! perfect_swap_exists && unmatched_pairs.count ( inverse ) > 0 )
                perfect_swap_exists = true;
        }
    }

    // we have to do at least one swap so if all match then we return 2 less
    if( matching_pair_count == N )
        return matching_pair_count - 2;
    
    if( perfect_swap_exists )
        return matching_pair_count + 2;

    bool s_has_duplicates = false;
    for(auto pair : schar_count )
    {
        if( pair.second > 1 )
        {
            s_has_duplicates = true;
            break;
        }
    }
    if( s_has_duplicates )
        return matching_pair_count - 1;
    
    
    return matching_pair_count - 2;
  // Write your code here
  
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
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
