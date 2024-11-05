#include <stdio.h>
#include <vector>


void dumpVector(std::vector<int> numbers)
{
    printf("[");
    for(long unsigned int index=0;index<numbers.size();index++)
    {
        if( index > 0 )
            printf(",");
        printf("%d",numbers[index]);
    }
    printf("]\n");
}

int main( int argc, char **argv)
{
    printf("\nLeetcode #0239 - Sliding Window Maximum\n");

    {
        std::vector nums = {1,3,-1,-3,5,3,6,7};
        std::vector<int> results;
        int window_size = 3;

        printf("\nInput Array   : ");
        dumpVector(nums );
        printf("Window size   : %d\n", window_size );

        for(long unsigned int index=0;index<nums.size()-window_size+1;index++)
        {
            int max = 0;
            for(int window=0;window<window_size;window++)
            {
                if( nums[window+index] > max )
                    max = nums[window+index];
            }
            results.push_back( max );
        }
    
        printf("Output Array  : ");
        dumpVector( results );
    }

    {
        std::vector nums = {1};
        std::vector<int> results;
        int window_size = 1;

        printf("\nInput Array  : ");
        dumpVector(nums );
        printf("Window size  : %d\n", window_size );

        for(long unsigned int index=0;index<nums.size()-window_size+1;index++)
        {
            int max = 0;
            for(int window=0;window<window_size;window++)
            {
                if( nums[window+index] > max )
                    max = nums[window+index];
            }
            results.push_back( max );
        }
    
        printf("Output Array : ");
        dumpVector( results );
    }



    
    return 0;
}
