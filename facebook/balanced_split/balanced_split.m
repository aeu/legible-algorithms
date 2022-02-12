// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//


#import <Foundation/Foundation.h>
#import <limits.h>

void dumpArray(NSArray *data)
{
    for( int index = 0; index < [data count]; index++)
    {
        NSNumber *current = [data objectAtIndex:index];
        printf( "%2d " , [current intValue]);
    }
    printf("\n");
}



bool checkArrays(NSMutableArray *array_a, NSMutableArray *array_b)
{
    printf("check arrays\n\t");
    dumpArray( array_a );
    printf("\t");
    dumpArray( array_b );
    int array_a_sum = 0;
    int array_b_sum = 0;
    int smallest_b = INT_MAX;
    int biggest_a  = INT_MIN;
    for(int index=0;index<[array_a count];index++)
    {
        int current_a = [(NSNumber *)[array_a objectAtIndex:index] intValue];
        array_a_sum += current_a;
        if( current_a > biggest_a )
            biggest_a = current_a;
    }
    for(int index=0;index<[array_b count];index++)
    {
        int current_b = [(NSNumber *)[array_b objectAtIndex:index] intValue]; 
        array_b_sum += current_b;
        if( current_b < smallest_b )
            smallest_b = current_b;
    }
    if( array_a_sum != array_b_sum )
    {
        return false;
    }

    if( biggest_a >= smallest_b )
    {
        return false;
    }
  
    return true;
}


bool balancedSplitExists(NSMutableArray *numbers)
{
    NSMutableArray *array_b = [[NSMutableArray alloc] init];
    NSMutableArray *array_a = [[NSMutableArray alloc] initWithArray:numbers];
    
    bool done = false;
    while(! done )
    {
        int biggest_so_far   = 0;
        int index_of_biggest = 0;
        for(int index=0;index<[array_a count];index++)
        {
            NSNumber *current_num = (NSNumber *)[array_a objectAtIndex:index];
            int current = [current_num intValue];
            if( current > biggest_so_far )
            {
                biggest_so_far = current;
                index_of_biggest = index;
            }
        }
        [array_a replaceObjectAtIndex:index_of_biggest withObject:@0];
        [array_b addObject:[NSNumber numberWithInt:biggest_so_far]];
        done = checkArrays(array_a, array_b);
        if( [array_b count] == [array_a count] )
        {
            break;
        }
    }
    return done;
}


int main(int argc, char **argv)
{
    {
        NSMutableArray *nums = [[NSMutableArray alloc] initWithObjects:@1, @5, @7, @1, nil];
        if( balancedSplitExists( nums ) )
            printf("balanced split exists\n");
        else
            printf("balanced split does not exist\n");
    }
        
    {
        NSMutableArray *nums = [[NSMutableArray alloc] initWithObjects:@12, @7, @6, @7, @6, nil];
        if( balancedSplitExists( nums ) )
            printf("balanced split exists\n");
        else
            printf("balanced split does not exist\n");
    }
        
    return 0;
}
