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

std::vector<int> buildValidLeftPhotographers(int N, string C, int X, int Y)
{
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
std::vector<int> buildValidLeftBackdrops(int N, string C, int X, int Y)
{
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


std::vector<int> buildValidRightBackdrops(int N, string C, int X, int Y)
{
    std::string C_rev = C;
    std::reverse(C_rev.begin(), C_rev.end());
    
    // Compute left counts on the reversed string
    std::vector<int> leftCounts_rev = buildValidLeftBackdrops(N, C_rev, X, Y);
    
    // Reverse the result to get the right counts in original order
    std::reverse(leftCounts_rev.begin(), leftCounts_rev.end());
    return leftCounts_rev;
}

std::vector<int> buildValidRightPhotographers(int N, string C, int X, int Y)
{
    std::string C_rev = C;
    std::reverse(C_rev.begin(), C_rev.end());
    
    std::vector<int> leftCounts_rev = buildValidLeftPhotographers(N, C_rev, X, Y);
    std::reverse(leftCounts_rev.begin(), leftCounts_rev.end());
    return leftCounts_rev;
}

int getArtisticPhotographCount(int N, string C, int X, int Y) {


    std::vector<int> left_photographers = buildValidLeftPhotographers(N,C,X,Y);
    std::vector<int> left_backdrops     = buildValidLeftBackdrops(N,C,X,Y);
    
    std::vector<int> right_photographers = buildValidRightPhotographers(N,C,X,Y);
    std::vector<int> right_backdrops     = buildValidRightBackdrops(N,C,X,Y);

    int artistic_photographs = 0;
    for(int current =0;current<N;current++)
    {
        if( C[current] == 'A' )
        {
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
    {
        int N = 5;
        std::string C = "APABA";
        int X = 1;
        int Y = 2;
        int expected_return = 1;
        
        int art_phot_count = getArtisticPhotographCount(N,C,X,Y);

        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
    }
    {
        int N = 5;
        std::string C = "APABA";
        int X = 2;
        int Y = 3;
        int expected_return = 0;
        
        int art_phot_count = getArtisticPhotographCount(N,C,X,Y);

        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
    }
    {
        int N = 8;
        std::string C = ".PBAAP.B";
        int X = 1;
        int Y = 3;
        int expected_return = 3;
        
        int art_phot_count = getArtisticPhotographCount(N,C,X,Y);

        if( art_phot_count == expected_return )
            std::cout << "pass" << std::endl;
        else
            std::cout << "fail, retval should be " << expected_return << " you returned : " << art_phot_count << std::endl;
    }
}
