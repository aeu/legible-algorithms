#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
// Add any extra import statements you may need here

using namespace std; 

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S ) {

    std::vector<long long> table (N+1,0);
    long long diner_count = 0; 
    for(auto current : S )
    {
	table[current] = 1;
    }
    long long lead = 0;
    long long diner = 0;
    long long trail = 0;
    int diners_in_window = 0;
    std::cout << "N:  " << N << std::endl;
    while( diner < N )
    {
	if((lead < N ) && ( table[lead] == 1 ))
	{
	    diners_in_window++;
	    std::cout << "found a diner at position : " << lead << " diners in window count is now : " << diners_in_window << std::endl;
	}
	if( lead >= K ) 
	{
	    if(( diners_in_window == 0 ))
	    {
		std::cout << "position : " << diner << " is available, no other diners in range, seating someone" << std::endl;
		table[diner] = 1;
		diner_count++;
		diners_in_window++;
	    }
	    diner++;
	}
	if( lead >= ( 2 * K ) )
	{
	    if(( trail < N ) && ( table[trail] == 1 ))
	    {
		diners_in_window--;
	    }
	    trail++;
	}
	lead++;
    }
    return diner_count;
}


int main()
{
    {
	int N = 10;
	int K = 1;
	int M = 2;
	vector<long long> S = { 2,6 };
	long long expected = 3;
	long long max_diner_count = getMaxAdditionalDinersCount(N, K, M, S );
	if( expected == max_diner_count )
	{
	    std::cout << "Pass " << std::endl;
	}
	else
	{
	    std::cout << "Fail.  Expected: " << expected << " received : " << max_diner_count << std::endl;
	}
    }
    {
	int N = 15;
	int K = 2;
	int M = 3;
	vector<long long> S = { 11,6,14 };
	long long expected = 1;
	long long max_diner_count = getMaxAdditionalDinersCount(N, K, M, S );
	if( expected == max_diner_count )
	{
	    std::cout << "Pass " << std::endl;
	}
	else
	{
	    std::cout << "Fail.  Expected: " << expected << " received : " << max_diner_count << std::endl;
	}
    }

}
