#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int choose_over_limit(int n, int lim)
{
  int j = n;
  int choose = n;
  for (int i = 2; i <= n/2; i++) {
    j--;
    choose *= j;
    choose /= i;
    if (choose > lim) {
      return n - 2 * i + 1;
    }
  }
  return 0;
}

int compute_product()
{
  const int in = 100;
  const int limit = 1E6;

  vector<int> v(in);
  iota(begin(v), end(v), 1);

  return accumulate(begin(v), end(v), 0, 
    [] (int sum, int n) { return sum + choose_over_limit(n, limit); });
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
