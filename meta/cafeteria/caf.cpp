#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
// Add any extra import statements you may need here

using namespace std; 

void dumpLongs(vector<long long> S) {
    for (auto current : S) {
        cout << current << ", ";
    }
    cout << endl;
}

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S )
{
    std::sort(S.begin(),S.end());
    long long additional = 0;
    long long gap;
    if( S[0] > 1 )
    {
        gap = S[0] - 1;
        additional += gap / ( K + 1 ) ;
    }
    
    for(int index=0;index<S.size()-1;index++)
    {
        gap = S[index+1] - S[index] - 1;
        if( gap > K )
        {
            additional += ( gap - K ) / ( K + 1 );
        }
    }
    gap = N - S[S.size()-1] ;
    additional += gap / ( K + 1 );
    return additional;
}


int main() {
    {
        int N = 10;
        int K = 1;
        int M = 2;
        vector<long long> S = {2, 6};
        long long expected = 3;
        long long max_diner_count = getMaxAdditionalDinersCount(N, K, M, S);
        cout << "Test case 1: " << (expected == max_diner_count ? "Pass" : "Fail") 
             << " (expected " << expected << ", got " << max_diner_count << ")\n";
    }
    {
        int N = 15;
        int K = 2;
        int M = 3;
        vector<long long> S = {11, 6, 14};
        long long expected = 1;
        long long max_diner_count = getMaxAdditionalDinersCount(N, K, M, S);
        cout << "Test case 2: " << (expected == max_diner_count ? "Pass" : "Fail") 
             << " (expected " << expected << ", got " << max_diner_count << ")\n";
    }

    return 0;
}




