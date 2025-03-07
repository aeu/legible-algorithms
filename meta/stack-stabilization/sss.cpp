#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
// Add any extra import statements you may need here

using namespace std; 



int getMinimumDeflatedDiscCount(int N, vector<int> R)
{
    int num_deflated = 0;
 
    for(int index=R.size()-2;index>=0;index--)
    {
        int current = R[index];
        int below   = R[index+1];

        if( current <= 1 )
            return -1;

        if( current >= below )
        { 
            num_deflated++;
            current = below - 1;
            R[index] = current;
            if( current <= 0 )
                return -1;
        }
    }
    return num_deflated;
}


int main(int argc, char **argv)
{
    {
        int N = 5;
        vector<int> R = {2,5,3,6,5};
        int expected = 3;
        int disc_count = getMinimumDeflatedDiscCount(N, R);
        cout << "Result: " << (expected == disc_count ? "Pass" : "Fail") 
             << " (expected " << expected << ", got " << disc_count << ")\n";

    }
    {
        int N = 3;
        vector<int> R = {100,100,100};
        int expected = 2;
        int disc_count = getMinimumDeflatedDiscCount(N, R);
        cout << "Result: " << (expected == disc_count ? "Pass" : "Fail") 
             << " (expected " << expected << ", got " << disc_count << ")\n";

    }
    {
        int N = 4;
        vector<int> R = {6,5,4,3};
        int expected = -1;
        int disc_count = getMinimumDeflatedDiscCount(N, R);
        cout << "Result: " << (expected == disc_count ? "Pass" : "Fail") 
             << " (expected " << expected << ", got " << disc_count << ")\n";

    }
}
