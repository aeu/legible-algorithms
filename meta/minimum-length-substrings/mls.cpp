#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
// Add any extra import statements you may need here

using namespace std; 


// Add any helper functions you may need here

void dumpDistribution(std::map<char,int> &dis)
{
    for(auto pair: dis )
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

bool isSubstring(std::map<char,int> &inner,
                 std::map<char,int> &candidate)
{
    for(auto pair : inner )
    {
        if( candidate.find( pair.first ) == candidate.end() )
            return false;
        if( candidate[ pair.first ] < pair.second )
            return false;
    }
    return true;
}


int minLengthSubstring(string s, string t)
{
  // Write your code here

    if( t.length() > s.length() )
        return -1;
    
    std::map<char,int> s_dist;
    std::map<char,int> t_dist;
    int min_length = INT_MAX;
    for( char c : t )
    {
        t_dist[c]++;
    }
    int left = 0;
    int right = t.size()-1;
    for(int index=left;index<=right;index++)
    {
        s_dist[ s[index] ]++;
    }

    while( right < s.size())
    {
        while( isSubstring(t_dist,s_dist))
        {
            min_length = std::min(min_length, (right-left+1));
            s_dist[s[left]]--;
            if( s_dist[s[left]] == 0 )
                s_dist.erase(s[left]);
            left++;
        }
        right++;
        if( right >= s.size() )
            break;
        s_dist[ s[right] ]++;
    }
    if( min_length < INT_MAX )
        return min_length;
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

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
