#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

long long compute_product()
{
  vector<long long> v;

  for (long long i = 1; i < 2E6; i++)
    if (is_prime(i)) v.push_back(i);

  return accumulate(begin(v), end(v), (long long)0);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
