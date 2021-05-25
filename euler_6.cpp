#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int compute_product()
{
  vector<int> v(100);
  iota(begin(v), end(v), 1);

  int square_sum = accumulate(begin(v), end(v), 0,
    [] (int sum, int n) { return sum + n * n; });
  int sum = accumulate(begin(v), end(v), 0);

  return sum*sum - square_sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
