// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
//
#include <stdio.h>
#include <string.h>

int reverse(int x)
{
    int retval;

    // we know that the limit is 2^32, which is a 10 character long
    // string, so 16 is enough space
    
    char in[16];
    char out[16];
    memset( &in[0], 0, 16 );
    memset( &out[0], 0, 16 );
    
    sprintf( in, "%d", x );
    int out_index = 0;
    
    // loop through the string backwards, and copy it character by
    // character into the output buffer.  Also skip the sign, because
    // we will deal with that later.
    
    char *out_ptr = &out[0];
    for(int loop=strlen(in)-1; loop>=0; loop-- )
    {
        if( in[loop] != '-' )
        {
            *out_ptr++ = in[loop];
        }
    }

    // we have to return a 0 if the reversing process makes it not be
    // an integer, so return 0 if sscanf returns anything other than 1
    // (sscanf returns the number of items successfully converted).
    
    int scanres = sscanf( (char *)&out[0], "%d", &retval );
    if( scanres != 1 )
        return 0;

    // if the input was negative, make the output negative as well.
    
    if( x < 0 )
        retval *= -1;
    
    return retval;
}

int main(int argc, char **argv)
{
    printf("%d\n", reverse( 123 ));
    printf("%d\n", reverse( -123 ));
    printf("%d\n", reverse( 120 ));
}
