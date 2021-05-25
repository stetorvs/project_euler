#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

long long self_power(int n)
{
  long long p = 1;
  for (int i = 0; i < n; i++) {
    p *= (long long)n;
    while (p > 10000000000LL) p -= 10000000000LL;
  }
  return p;
}

long long compute_product()
{
  const int in = 1E3;

  long long s = 0;
  for (int i = 1; i <= in; i++) {
    s += self_power(i);
    while (s > 10000000000LL) s -= 10000000000LL;
  }
  return s;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
