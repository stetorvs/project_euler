#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>
#include <set>
#include <vector>

using namespace std;

int sum_fifth (int n)
{
  vector<int> v;
  while (n) {
    v.push_back(n%10);
    n /= 10;
  }
  return accumulate(begin(v), end(v), 0,
    [] (int sum, int n) { return sum + n*n*n*n*n; });
}

int compute_product()
{
  int sum = 0;
  for (int i = 2; i < 1E6; i++) {
    if (i == sum_fifth(i)) {
      sum += i;
      cout << sum << '\n';
    }
  }
  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
