#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i*i < n; i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

int compute_product()
{
  const long long in = 600851475143;

  for (long long l = 2; l < in; l++)
    if (in % l == 0 && is_prime(in / l))
      return in / l;

  return 1;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
