#include <stdio.h>
#include <time.h>

int mask;
unsigned long long sol = 0;

void nqueens(int pos, int r, int d1, int d2) {
  unsigned long long c = ~pos & mask;
  while(c) {
    unsigned long long i = -c & c, newd1, newd2;
      if (r+i == mask) {
        ++sol;
        return;
      }
      newd1 = (d1 + i) >> 1,
      newd2 = (d2 + i) << 1;
      nqueens(((r+i) | newd1 | newd2), r+i ,newd1, newd2);
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
     nqueens((1 << (N / 2)) - 1, 0, 0,0);
     printf("Number of all solutions: %llu\n", 2*sol);
  } else {
         nqueens((1 << ((N / 2) + 1)) - 1, 0, 0,0);
         unsigned long long centralSol = sol;
         sol = 0;
         nqueens(~(1 << (N / 2)), 0, 0, 0);
         printf("Number of all solutions: %llu\n", 2*centralSol + sol);
         }

  te = clock();

  printf("Time: %f\n" , (te - tb) / CLOCKS_PER_SEC);
}
