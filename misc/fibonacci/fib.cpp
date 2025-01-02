#include <stdio.h>



int generateFibs(int depth)
{
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
    printf("testing with arg of %d\n", depth);
    int result = generateFibs(depth);
    printf("result: %d\n", result );
  }
}
