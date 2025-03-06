#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>

using namespace std;


// Write any include statements here

int getMaximumEatenDishCount(int N, vector<int> D, int K)
{
  int right = 0;
  int dish_count = D.size();
  std::deque<int> recently_eaten;
  std::set<int> eaten_set;
  int eaten_count = 0;
  while( right < dish_count )
  {
    int current_dish = D[right];
    if( eaten_set.find( current_dish ) == eaten_set.end() )
    {
      eaten_count++;
      recently_eaten.push_front(current_dish);
      eaten_set.insert(current_dish);
      if( recently_eaten.size() > K )
      {
        int oldest = recently_eaten.back();
        recently_eaten.pop_back();
        eaten_set.erase(oldest);
      }
    }
    right++;
  }   
  return eaten_count;
}


int main() {
  {
    std::vector<int> values = { 1,2,3,3,2,1 };
    int N = 6;
    int K = 1;
    int eaten_count = getMaximumEatenDishCount( N, values, K );
    if( eaten_count == 5 )
      std::cout << "pass" << std::endl;
    else
      std::cout << "fail, retval should be 5 you returned : " << eaten_count << std::endl;
  }
  {
    std::vector<int> values = { 1,2,3,3,2,1 };
    int N = 6;
    int K = 2;
    int eaten_count = getMaximumEatenDishCount( N, values, K );
    if( eaten_count == 4 )
      std::cout << "pass" << std::endl;
    else
      std::cout << "fail, retval should be 4 you returned : " << eaten_count << std::endl;
  }
  {
    std::vector<int> values = { 1,2,1,2,1,2,1 };
    int N = 7;
    int K = 2;
    int eaten_count = getMaximumEatenDishCount( N, values, K );
    if( eaten_count == 2 )
      std::cout << "pass" << std::endl;
    else
      std::cout << "fail, retval should be 2 you returned : " << eaten_count << std::endl;
  }
  
}
