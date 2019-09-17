// fibo.c: Fibonacci Series using Dynamic Programming                                    
#include <stdio.h>

int fibo(int n) {
  int f[n+1];
  int i;

  if(n < 1)
    return 0;

  f[0] = 0; // Initial values
  f[1] = 1;
  for (i = 2; i <= n; i = i + 1) {
      /* Add the previous 2 numbers in the series                               
         and store it */
      f[i] = f[i-1] + f[i-2];
    }
  return f[n];
}
