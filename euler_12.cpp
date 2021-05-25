#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int num_divisors(int n)
{
  int sum = 0, i;
  for (i = 1; i < sqrt(n); i++)
    if (n % i == 0)
      sum += 2;

  if (i*i == n) sum++;

  return sum;
}

long long compute_product()
{
  int a = 1, count = 1;
  while (num_divisors(a) <= 500) {
    count++;
    a += count;
  }

  return a;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
