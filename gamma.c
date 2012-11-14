#include <math.h>
#include <stdio.h>

double lcombination(int N, int n) { return lgamma((double)(N+1))-lgamma((double)(n+1))-lgamma((double)(N-n+1)); }
double probability(int N, int n, int m, int k) 
        { return exp(lcombination(m,k)+lcombination(N-m,n-k)-lcombination(N,n)); }


int main(int argc, char **argv)
{
  int N = 12829, n = 4276, m = 11600, k = 4268, K = k+1, i;
  double firstprobability = probability(N, n, m, k), sum = firstprobability;
  printf("1st%lf ", firstprobability);
  printf("2nd%lf ", firstprobability*(double)(m-K+1)/(double)(K)*(double)(n-K+1)/(double)(N-m-n+K));
  printf("2nd %lf \n", probability(N, n, m, k+1));
  for (i = 1; i +k <= n && i+k <= m; i++) 
    {
     sum += probability(N, n, m, k+i);
    }
  printf("sum %.20lf\n", sum);
  return 0;

}
