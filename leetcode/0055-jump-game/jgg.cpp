#include <stdio.h>
#include <vector>
#include <iostream>

void dumpValues(std::vector<int>& values)
{
    bool first_time = true;
    std::cout << "[" ;
    for(auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


int canGetHere(std::vector<int>& nums,
               int curpos)
{
    for(int index=curpos-1;index>=0;index--)
    {
        int value = nums[index];
        if(( index + value ) >= curpos )
        {
            return index;
        }
    }
    return -1;
}

bool canJump(std::vector<int>& nums)
{
    int curpos = nums.size()-1;
    while( curpos > 0 )
    {
        int can_get_here_from = canGetHere(nums,curpos);
        if( can_get_here_from == -1 )
            return false;
        curpos = can_get_here_from;
    }
    return true;
}

int main( int argc, char **argv)
{
    printf("Leetcode #0055 - Jump Game\n");

    {
        std::cout << "Example: 1" << std::endl;
        std::vector<int> nums = { 2,3,1,1,4 };
        dumpValues(nums);
        bool can_jump = canJump(nums);
        std::cout << "Can Jump : " << can_jump << std::endl;
    }
    {
        std::cout << "Example: 1" << std::endl;
        std::vector<int> nums = { 3,2,1,0,4 };
        dumpValues(nums);
        bool can_jump = canJump(nums);
        std::cout << "Can Jump : " << can_jump << std::endl;
    }
    return 0;
}
