#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 28123;

  vector<int> v(in);
  iota(begin(v), end(v), 1);

  unordered_set<int> s;

  copy_if(begin(v), end(v), inserter(s, begin(s)),
    [&v] (int n) {
        return accumulate(begin(v), begin(v) + n - 1, 0,
          [n] (int sum, int s) { return sum + (n % s == 0 ? s : 0); }) > n;
      });

  unordered_set<int> vsum;

  for (auto it1 = begin(s); it1 != end(s); ++it1) {
    for (auto it2 = it1; it2 != end(s); ++it2) {
      int sum = *it1 + *it2;
      if (sum <= in) {
        vsum.insert(sum);
      }
    }
  }

  return in * (in+1) / 2 - accumulate(begin(vsum), end(vsum), 0);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
