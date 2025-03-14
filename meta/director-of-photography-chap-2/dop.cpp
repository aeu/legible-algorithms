// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>

using namespace std;

void dumpVector(std::vector<int> nums )
{
    for( auto curr : nums )
        std::cout << curr << ", " ;
    std::cout << endl;
}

std::vector<int> buildValidLeftPhotographers(const std::string &C, int X, int Y)
{
    int N = C.size();
    std::vector<int> photographers(N,0);
    int num_photographers = 0;
    for(int window=0;window<N;window++)
    {
        if( window >= X )
        {
            if( C[window-X] == 'P' )
            {
                num_photographers++;
            }
        }
        if( window >= Y+1 )
        {
            if( C[window-Y-1] == 'P' )
            {
                num_photographers--;
            }
        }
        photographers[window] = num_photographers;
    }
    return photographers;
}
std::vector<int> buildValidLeftBackdrops(const std::string &C, int X, int Y)
{ 
    int N = C.size();
    std::vector<int> backdrops(N,0);
    int num_backdrops = 0;
    for(int window=0;window<N;window++)
    {
        if( window >= X )
        {
            if( C[window-X] == 'B' )
            {
                num_backdrops++;
            }
        }
        if( window >= Y+1 )
        {
            if( C[window-Y-1] == 'B' )
            {
                num_backdrops--;
            }
        }
        backdrops[window] = num_backdrops;
    }
    return backdrops;
}


std::vector<int> buildValidRightBackdrops(const std::string &C, int X, int Y)
{
    int N = C.size();
    std::vector<int> backdrops(N,0);
    int num_backdrops = 0;
    for (int window = N-1; window >= 0; window--)
    {
        // Gain valid backdrop at index window+X
        if (window + X < N && C[window+X] == 'B')
        {
            num_backdrops++;
        }
        // Lose the backdrop at index window+Y+1 (it just left the window)
        if (window + Y + 1 < N && C[window+Y+1] == 'B')
        {
            num_backdrops--;
        }
        backdrops[window] = num_backdrops;
    }
    return backdrops;
}

std::vector<int> buildValidRightPhotographers(const std::string &C, int X, int Y)
{
    int N = C.size();
    std::vector<int> photographers(N,0);
    int num_photographers = 0;
    for (int window = N-1; window >= 0; window--)
    {
        if (window + X < N && C[window+X] == 'P')
        {
            num_photographers++;
        }
        if (window + Y + 1 < N && C[window+Y+1] == 'P')
        {
            num_photographers--;
        }
        photographers[window] = num_photographers;
    }
    return photographers;
}


long long getArtisticPhotographCount(const std::string &C, int X, int Y) {

    int N = C.size();

    std::vector<int> left_photographers = buildValidLeftPhotographers(C,X,Y);
    std::vector<int> left_backdrops     = buildValidLeftBackdrops(C,X,Y);
    
    std::vector<int> right_photographers = buildValidRightPhotographers(C,X,Y);
    std::vector<int> right_backdrops     = buildValidRightBackdrops(C,X,Y);

    long long artistic_photographs = 0;
    for(int current =0;current<N;current++)
    {
        if( C[current] == 'A' )
        {
            // std::cout << "Checking A at index: " << current << std::endl;
            //  std::cout << "  Left photographers: " << left_photographers[current] << std::endl;
            //  std::cout << "  Right backdrops: " << right_backdrops[current] << std::endl;
            //  std::cout << "  Right photographers: " << right_photographers[current] << std::endl;
            //  std::cout << "  Left backdrops: " << left_backdrops[current] << std::endl;
            
            int left_photogs = left_photographers[current];
            int right_drops = right_backdrops[current];
            artistic_photographs += ( left_photogs * right_drops );
            
            int right_photogs = right_photographers[current];
            int left_drops = left_backdrops[current];
            artistic_photographs += ( right_photogs * left_drops );
        }
        
    }
    return artistic_photographs;
}

int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::string C = "APABA";
        int X = 1;
        int Y = 2;
        int expected_return = 1;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = "APABA";
        int X = 2;
        int Y = 3;
        int expected_return = 0;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = ".PBAAP.B";
        int X = 1;
        int Y = 3;
        int expected_return = 3;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = "P........A........B";
        int X = 5;
        int Y = 10;
        int expected_return = 1;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = "APABA";
        int X = 1;
        int Y = 2;
        int expected_return = 1;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = "APABA";
        int X = 2;
        int Y = 3;
        int expected_return = 0;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = ".PBAAP.B";
        int X = 1;
        int Y = 3;
        int expected_return = 3;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = "P..A..B";
        int X = 2;
        int Y = 2;
        int expected_return = 0;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = "A.PB.";
        int X = 1;
        int Y = 3;
        int expected_return = 0;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = ".PB.A";
        int X = 1;
        int Y = 3;
        int expected_return = 0;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
    {
        std::string C = "P.AA..B...";
        int X = 1;
        int Y = 5;
        int expected_return = 2;
        
        int art_phot_count = getArtisticPhotographCount(C,X,Y);

        std::cout << "Testcase #" << test_case++ << "   ";
        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
        {
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
            std::cout << "X : " << X << std::endl;
            std::cout << "Y : " << Y << std::endl;
            std::cout << "C : " << C << std::endl;
        }
    }
#if 0
#endif
}
