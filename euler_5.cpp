#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= n/2; i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

int compute_product()
{
  const int in = 20;

  vector<int> v(in);
  iota(begin(v), end(v), 1);

  vector<int> factors;

  auto bound = stable_partition(begin(v), end(v), is_prime);

  for (int exp = 1; exp < log2(in) + 1; exp++)
    for_each(begin(v), bound,
      [&factors, exp] (int n) { if (pow(n, exp) <= in) factors.push_back(n); });

  return accumulate(begin(factors), end(factors), 1, multiplies<int>());
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
