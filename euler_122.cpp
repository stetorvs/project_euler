#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class C {
  public:
    vector<int> v;
    vector<int> s;
    int n;
    int sum;

    C(int n) : n(n)
    {
      v.resize(n+1);
      iota(begin(v)+1, end(v), 0);
    }

    int compute()
    {
      sum = 1;
      recurse();
      int i = 0;
      for (auto a : v) cout << i++ << ' ' << a << '\n';
      return accumulate(begin(v)+1, end(v), 0);
    }

  private:
    void recurse();
};

void C::recurse()
{
  if (sum <= n && s.size() <= v[sum]) {
    v[sum] = s.size();
    s.push_back(sum);
    auto endit = s.rend();
    for (auto it = s.rbegin(); it != endit; ++it) {
      sum += *it;
      recurse();
      sum -= *it;
    }
    s.pop_back();
  }
}

int compute_sum()
{
  const int in = 200;

  C c(in);

  return c.compute();
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
