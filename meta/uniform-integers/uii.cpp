#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here

long long getNextUniformInteger(long long  current)
{
    long long  log = std::log10(current);
    long long  base = 1;
    long long  next = 0;
    while( log > 0 )
    {
        base = ( base * 10 ) + 1;
        log--;
    }
    next = base;
    while( next <= current )
        next += base;
    if(( next % 10 ) == 0 )
        next += 1;
    return next;
}

long long  getUniformIntegerCountInInterval(long long A, long long B)
{
    long long  start = A-1;
    long long  end = B+1;
    long long  count = 0;
    long long  next = getNextUniformInteger(start);
    while( next <= end )
    {
        count++;
        next = getNextUniformInteger(next);
        std::cout << "Next " << next << std::endl;
    }

    return count;
}



int main() {


    long long  N = getNextUniformInteger(2);
    std::cout << "N : " << N << std::endl;
    
    {
        long long  A = 75;
        long long  B = 300;
        long long  expected = 5;

        long long  answer = getUniformIntegerCountInInterval(A, B);

        if( answer == expected )
            std::cout << "Pass" << std::endl;
        else
            std::cout << "Fail, expected :  " << expected << " got " << answer << std::endl;
    }
    {
        long long  A = 1;
        long long  B = 9;
        long long  expected = 9;

        long long  answer = getUniformIntegerCountInInterval(A, B);

        if( answer == expected )
            std::cout << "Pass" << std::endl;
        else
            std::cout << "Fail, expected :  " << expected << " got " << answer << std::endl;
    }
    {
        long A = 999999999999;
        long B = 999999999999;
        long long  expected = 1;

        long long  answer = getUniformIntegerCountInInterval(A, B);

        if( answer == expected )
            std::cout << "Pass" << std::endl;
        else
            std::cout << "Fail, expected :  " << expected << " got " << answer << std::endl;
    }
    return 0;
}
