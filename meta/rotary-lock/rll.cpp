#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>

using namespace std;
using namespace std;
// Write any include statements here


long distanceTo(int current, int destination, int N)
{
    if( current == destination )
        return 0;

    int going_right;
    int going_left;
        
    if( current < destination )
    {
        going_right = destination - current;
        going_left = current + N - destination;
    }
    else if( current > destination )
    {
        going_right = N - current + destination;
        going_left = current - destination;
    }
    return std::min( going_right, going_left );
}


long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  // Write your code here
    long long retval = 0;
    int current_position = 1;
    for(auto next : C )
    {
        retval += distanceTo(current_position, next, N );
        current_position = next;
    }
    
    return retval;
}


int main(int argc, char **argv)
{
    {
        int n = 3;
        int m = 3;
        std::vector<int> combination = { 1,2,3};
        int mincode = getMinCodeEntryTime( n, m, combination );
        int expected = 2;
        if( mincode == expected )
            std::cout << "pass" << std::endl;
        else 
            std::cout << "fail got " << mincode << " should be " << expected << std::endl;
           
    }
    {
        int n = 10;
        int m = 4;
        std::vector<int> combination = { 9,4,4,8};
        int mincode = getMinCodeEntryTime( n, m, combination );
        int expected = 11;
        if( mincode == expected )
            std::cout << "pass" << std::endl;
        else 
            std::cout << "fail got " << mincode << " should be " << expected << std::endl;
           
    }
}
