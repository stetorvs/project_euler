#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>

using namespace std;

map<int, int> roll(const map<int, int>& st, int die)
{
  map<int, int> ds;
  for (int i = 1; i <= die; i++) {
    for (auto [val, cnt] : st) {
      ds[val+i] += cnt;
    }
  }
  return ds;
}

double compute_probability()
{
  map<int, int> ps;
  for (int i = 1; i <= 4; i++) {
    ps.emplace(i, 1);
  }
  map<int, int> pc;
  for (int i = 1; i <= 6; i++) {
    pc.emplace(i, 1);
  }

  for (int i = 0; i < 8; i++) {
    ps = roll(ps, 4);
  }
  for (int i = 0; i < 5; i++) {
    pc = roll(pc, 6);
  }

  int d4_total = (1<<18);
  int d6_total = 6*6*6*6*6*6;
  double prob = 0.;
  for (auto [val, cnt] : ps) {
    auto lb_it = pc.lower_bound(val);
    int acc = accumulate(begin(pc), lb_it, 0, []
      (int sum, auto& p) { return sum + p.second; });
    prob += static_cast<double>(cnt) / d4_total
      * static_cast<double>(acc) / d6_total;
  }

  return prob;
}

int main()
{
  cout.precision(7);
  cout << compute_probability() << '\n';

  return 0;
}
