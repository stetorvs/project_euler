#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

int compute_product()
{
  int num_primes = 0;

  int n;

  for (n = 2; num_primes < 10001; n++)
    num_primes += is_prime(n);

  return n - 1;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
