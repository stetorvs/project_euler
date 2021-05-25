#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class C {
public:
  C() : i(0), v(vector<bool>(10))
  {
    fill(begin(v), end(v), false);
    v[0] = true;
  }
  int compute() { recurse(5); return accumulate(begin(s), end(s), 0); }
private:
  void recurse(int);
  void check(int a, int b);

  int i;
  vector<bool> v;
  set<int> s;
};

void C::recurse(int n)
{
  if (n == 0) {
    int a1 = i % 1000;
    int a2 = i / 1000;
    check(a1, a2);
    int b1 = i % 10000;
    int b2 = i / 10000;
    check(b1, b2);
    return;
  }
  for (auto it1 = begin(v); it1 != end(v); ++ it1) {
    if (*it1) continue;
    *it1 = true;
    i *= 10;
    i += it1 - begin(v);
    recurse(n-1);
    i /= 10;
    *it1 = false;
  }
}

void C::check(int a, int b)
{
  int c = a * b;
  if (c >= 10000) return;
  vector<bool> v_copy = v;
  while (c) {
    if (v_copy[c % 10]) return;
    v_copy[c % 10] = true;
    c /= 10;
  }
  cout << a*b << '\n';
  s.insert(a*b);
}

int compute_product()
{
  C c;

  return c.compute();
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
