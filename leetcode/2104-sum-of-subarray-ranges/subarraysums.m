// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import <Foundation/Foundation.h>
#import <stdio.h>
#import "Ranges.h"

int main(int argc, char **argv)
{
    Ranges *summer = [[Ranges alloc] init];
    int example_1[] = {1,2,3};
    int sum_of_all_ranges = [summer sumSubarrays:example_1 startIndex:0 endIndex:2];
    printf("Example 1 : %d\n", sum_of_all_ranges );

    summer = [[Ranges alloc] init];
    int example_2[] = {1,3,3};
    sum_of_all_ranges = [summer sumSubarrays:example_2 startIndex:0 endIndex:2];
    printf("Example 2 : %d\n", sum_of_all_ranges );
    
    summer = [[Ranges alloc] init];
    int example_3[] = {4,-2,-3,4,1};
    sum_of_all_ranges = [summer sumSubarrays:example_3 startIndex:0 endIndex:4];
    printf("Example 3 : %d\n", sum_of_all_ranges );
    
}
