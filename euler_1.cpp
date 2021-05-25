#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int compute_sum()
{
  vector<int> v(1000);
  iota(begin(v), end(v), 0);

  return accumulate(begin(v), end(v), 0,
           [] (int sum, int n) { return sum + (n % 3 == 0 || n % 5 == 0 ? n : 0); });
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
