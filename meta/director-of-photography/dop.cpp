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


// Write any include statements here

int numValidLeftBackdrops(std::vector<int> backdrops, int mypos, int X, int Y )
{
    int valid_count = 0;
    for(auto current : backdrops )
    {
        if ( current > mypos )
            continue;
        int range = mypos - current;
        if( ( range >= X ) && ( range <= Y ))
            valid_count++;
    }
    return valid_count;
}
int numValidRightBackdrops(std::vector<int> backdrops, int mypos, int X, int Y )
{
    int valid_count = 0;
    for(auto current : backdrops )
    {
        if ( current < mypos )
            continue;
        int range = current - mypos;
        if( ( range >= X ) && ( range <= Y ))
            valid_count++;
    }
    return valid_count;
}
int numValidLeftPhotographers(std::vector<int> photographers, int mypos, int X, int Y )
{
    int valid_count = 0;
    for(auto current : photographers )
    {
        if ( current > mypos )
            continue;
        int range = mypos - current;
        if( ( range >= X ) && ( range <= Y ))
            valid_count++;
    }
    return valid_count;
}
int numValidRightPhotographers(std::vector<int> photographers, int mypos, int X, int Y )
{
    int valid_count = 0;
    for(auto current : photographers )
    {
        if ( current < mypos )
            continue;
        int range = current - mypos;
        if( ( range >= X ) && ( range <= Y ))
            valid_count++;
    }
    return valid_count;
}


int getArtisticPhotographCount(int N, string C, int X, int Y) {
    std::vector<int> actors;
    std::vector<int> backdrops;
    std::vector<int> photographers;

    for(int index=0;index<C.size();index++)
    {
        char current = C[index];
        if( current == 'A' )
            actors.push_back(index);
        else if( current == 'B' )
            backdrops.push_back(index);
        else if( current == 'P' )
            photographers.push_back(index);
    }
    int artistic_photographs = 0;
    for(auto current : actors )
    {
        int left_photogs = numValidLeftPhotographers(photographers, current, X, Y);
        int right_backdrops = numValidRightPhotographers(backdrops, current, X, Y);
        artistic_photographs += ( left_photogs * right_backdrops );

        int right_photogs = numValidRightPhotographers(photographers, current, X, Y);
        int left_backdrops = numValidLeftPhotographers(backdrops, current, X, Y);
        artistic_photographs += ( right_photogs * left_backdrops );
        
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
