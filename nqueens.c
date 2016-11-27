/*
author: Alessandro Nicolosi

The N-Queens problem:
How many ways are there to arrange N non-attacking
queens on an N x N chessboard?

This simple program count all solutions of N-Queens problem using
a backtracking approach optimized with bit operators.
This is a table of some known results:

N       # Solutions
1       1
2       0 
3       0 
4       2 
5       10 
6       4 
7       40  
8       92  
9       352 
10      724 
11      2680  
12      14200 
13      73712 
14      365596
15      2279184 
16      14772512 
17      95815104 
18      666090624
19      4968057848 
20      39029188884
21      314666222712
22      2691008701644
23      24233937684440

 */
#include <stdio.h>
#include <time.h>

int mask;
unsigned long long sol = 0;

void nqueens_backtracking(int pos, int r, int d1, int d2) {
  int c = ~pos & mask;
  while(c) {
    int i = -c & c, newd1, newd2;
      if (r+i == mask) {
        ++sol;
        return;
      }
      newd1 = (d1 + i) >> 1,
      newd2 = (d2 + i) << 1;
      nqueens_backtracking(((r+i) | newd1 | newd2), r+i ,newd1, newd2);
      c -= i;
   }
}

int main(int argc, char **argv)
{
  int N;
  double tb, te;
  
  printf("Insert the dimension of chekboard: ");
  scanf("%d", &N);

  if(N < 0 || N > 32) {
    printf("Error: N must be an integer between 0 and 32\n");
    return -1;
  }

  mask = (1 << N) - 1;

  tb = clock();

  if (N % 2 == 0)
  {
    nqueens_backtracking((1 << (N / 2)) - 1, 0, 0, 0);
    printf("Number of all solutions: %llu\n", 2*sol);
  } else {
    unsigned long long sol1;
    nqueens_backtracking((1 << ((N / 2) + 1)) - 1, 0, 0, 0);
    sol1 = sol;
    sol = 0;
    nqueens_backtracking(~(1 << (N / 2)), 0, 0, 0);
    printf("Number of all solutions: %llu\n", 2*sol1 + sol);
  }

  te = clock();

  printf("Time: %f\n" , (te - tb) / CLOCKS_PER_SEC);
  return 0;
}
