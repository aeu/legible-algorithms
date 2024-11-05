#include <stdio.h>
#include <vector>

int main( int argc, char **argv)
{
    printf("Leetcode #0233 - Number of Digit One\n");

    {
        int ones = 0;
        int value = 13;
        int saved = value;
        int mod;
        while( value > 0 )
        {
            mod = value % 10 ;
        
            if( mod == 1 )
                ones++;
        
            value /= 10;
        }
        printf("value: %d, num ones: %d\n", saved, ones );
    }
    
    {
        int ones = 0;
        int value = 0;
        int saved = value;
        int mod;
        while( value > 0 )
        {
            mod = value % 10 ;
        
            if( mod == 1 )
                ones++;
        
            value /= 10;
        }
        printf("value: %d, num ones: %d\n", saved, ones );
    }
    
    {
        int ones = 0;
        int value = 121451;
        int saved = value;
        int mod;
        while( value > 0 )
        {
            mod = value % 10 ;
        
            if( mod == 1 )
                ones++;
        
            value /= 10;
        }
        printf("value: %d, num ones: %d\n", saved, ones );
    }
    
    return 0;
}
