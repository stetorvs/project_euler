#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

bool sub_str_div(const vector<int> v)
{
  static const vector<int> p = {2,3,5,7,11,13,17};
  vector<int> d;
  int t = 10 * v[1] + v[2];
  for (auto it = begin(v) + 3; it != begin(v) + p.size() + 3; ++it) {
    t %= 100;
    t *= 10;
    t += *it;
    d.push_back(t);
  }

  for (size_t i = 0; i < p.size(); i++) {
    if (d[i] % p[i] != 0) return false;
  }
  return true;
}

long long compute_product()
{
  vector<int> v(10);
  iota(begin(v), end(v), 0);

  long long sum = 0;
  do {
    if (sub_str_div(v)) {
      long long n = 0;
      for (auto it = v.begin(); it != v.end(); ++it) {
        n *= 10;
        n += *it;
      }
      sum += n;
    }
  } while (next_permutation(begin(v), end(v)));

  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
