// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <stdio.h>

int generateFibs(int depth)
{
    if( depth <= 0 )
        return -1;

    if( depth == 1 )
        return  0;

    if( depth == 2 )
        return 1;

    int current = 2;
    int one_back = 1;
    int two_back = 0;
    depth-=3;
  
    while( depth > 0 )
    {
        int temp = current;
        current = current + one_back;
        two_back = one_back;
        one_back = temp;
        depth--;
    }
    return current;
}

int main(int argc, char **argv)
{
    {
        int depth = 7;
        printf("Generating the number %d Fibonacci number\n", depth);
        int result = generateFibs(depth);
        printf("Result: %d\n", result );
    }
}
