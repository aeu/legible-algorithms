#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
// Add any extra import statements you may need here

using namespace std; 

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S ) {

    std::sort(S.begin(),S.end());
    std::vector<long long> ranges();
    int start_position 0;
    for( auto current : S )
    {
	long long range = current - start_position - 1;
	ranges.push_back(range);
	start_position = current + 1;
    }

    for( auto current : ranges )
    {
	std::cout << "range : " << std::endl;
    }
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
