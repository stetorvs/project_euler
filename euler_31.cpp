#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

vector<int> vsum(const vector<int>a, const vector<int>b)
{
  vector<int> c;
  transform(begin(a), end(a), begin(b), back_inserter(c), plus<int>());
  return c;
}

vector<int> lu(const vector<int>a, const map<int,int>b, int c)
{
  vector<int> v(a.size());
  fill(begin(v), end(v), 0);
  v[b.at(c)] = 1;
  return v;
}

size_t compute_product()
{
  const int in = 200;
  vector<int> v = {1, 2, 5, 10, 20, 50, 100, 200};
  map<int, int>m;
  for (size_t i = 0; i < v.size(); i++)
    m[v[i]] = i;

  vector<set<vector<int>>> vs = {{}};
  for (int i = 1; i <= in; i++) {
    set<vector<int>> s;
    if (m.find(i) != m.end()) {
      s.insert(lu(v, m, i));
    }
    for (int n : v) {
      if (n >= i) continue;
      auto n_v = lu(v, m, n);
      for (auto pv : vs[i - n])
        s.insert(vsum(n_v, pv));
    }
    vs.push_back(s);
  }

  return vs[in].size();
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
