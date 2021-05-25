#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 1500000;
  vector<int> v(in+1);
  fill(begin(v), end(v), 0);

  vector<vector<int>> prim = {{3,4,5}};
  vector<vector<int>> triples;

  while (!prim.empty()) {
    auto t = prim.back();
    prim.pop_back();
    auto c = t;
    while (accumulate(begin(c), end(c), 0) <= in) {
      triples.push_back(c);
      c[0] += t[0];
      c[1] += t[1];
      c[2] += t[2];
    }
    if (accumulate(begin(t), end(t), 0) > in) continue;
    vector<int> c1 = {t[0] - 2*t[1] + 2*t[2], 2*t[0] - t[1] + 2*t[2], 2*t[0] - 2*t[1] + 3*t[2]};
    vector<int> c2 = {t[0] + 2*t[1] + 2*t[2], 2*t[0] + t[1] + 2*t[2], 2*t[0] + 2*t[1] + 3*t[2]};
    vector<int> c3 = {-t[0] +2*t[1] + 2*t[2], -2*t[0] + t[1] + 2*t[2], -2*t[0] + 2*t[1] + 3*t[2]};
    prim.push_back(c1);
    prim.push_back(c2);
    prim.push_back(c3);
  }

  for (auto a : triples) {
    v[accumulate(begin(a), end(a), 0)]++;
  }

  return count_if(begin(v), end(v), [] (int n) { return n == 1; });
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
