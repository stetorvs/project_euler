#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

int sum_divisor(int n)
{
  int sum = 0;
  for (int i = 1; i*2 <= n; i++) sum += (n % i == 0 ? i : 0);
  return sum;
}

int compute_product()
{
  const int in = 10000;

  vector<int> v(in);
  iota(begin(v), end(v), 0);

  return accumulate(begin(v), end(v), 0,
    [] (int sum, int a) { return sum + (sum_divisor(a) != a && sum_divisor(sum_divisor(a)) == a ? a : 0);});
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
