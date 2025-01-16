// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>


int maxConsecutiveOnes(const std::string &data,
                       const int length )
{
    return 1;
}


int main(int argc, char **argv)
{
    float max_vowels;

    std::cout << "Leetcode 1004 - Max Consecutive Ones III" << std::endl;
    {
        std::string data = "abciiidef";
        int k = 3;
        std::cout << "Counting: " << data << ", with k: " << k << std::endl;
        max_vowels = maxConsecutiveOnes(data, k );
        std::cout << "Maximum Number of Vowels : " << max_vowels << std::endl;
    }
}
