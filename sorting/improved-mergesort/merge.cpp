// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <vector>
#include <stdio.h>




void dumpValues(std::vector<int> values)
{
    for(auto current : values )
    {
        printf("%d ", current );
    }
    printf("\n");
}

void merge(std::vector<int> &inputs,
           int left_start,
           int left_end,
           int right_start,
           int right_end)
{
    std::vector<int> results;
    int left_merge_index = left_start;
    int right_merge_index = right_start;

    while((left_merge_index<left_end) && ( right_merge_index<right_end))
    {
        if( inputs[left_merge_index] < inputs[right_merge_index] )
        {
            results.push_back( inputs[left_merge_index]);
            left_merge_index++;
        }
        else
        {
            results.push_back( inputs[right_merge_index]);
            right_merge_index++;
        }
    }
    while( left_merge_index < left_end )
    {
        results.push_back( inputs[left_merge_index]);
        left_merge_index++;
    }
    while( right_merge_index < right_end )
    {
        results.push_back( inputs[right_merge_index]);
        right_merge_index++;
    }
    for(int index=0;index<(int)results.size();index++)
    {
        inputs[left_start+index] = results[index];
    }
}

void mergeSort(std::vector<int> &inputs,
               int start,
               int end)
{
    if(( end - start ) <= 1 )
        return;
    
    int left_start  = start;
    int mid         = start + ( end - start ) / 2 ;
    int right_end   = end;
    
    mergeSort( inputs, left_start, mid );
    mergeSort( inputs, mid, right_end );

    merge(inputs, left_start, mid, mid, right_end );
}




int main(int argc, char **argv)
{
    std::vector<int> inputs = { 2,7,13,1,8,45,5,9,12,55 };
    dumpValues(inputs);
    mergeSort(inputs,0,(int)inputs.size());
    dumpValues(inputs);
}
