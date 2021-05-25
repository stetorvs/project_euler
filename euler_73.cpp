#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Fraction {
  public:
    int num, den;

    Fraction(int n, int d) : num(n), den(d) {}
    bool operator < (const Fraction &b) const { return num * b.den < den * b.num; }
};

size_t compute_sum()
{
  const int in = 12000;

  Fraction l(1, 3);
  Fraction r(1, 2);

  set<Fraction> s;

  for (int i = 1; i < in; i++) {
    for (int j = i*2; j <= in; j++) {
      Fraction f(i, j);
      if (!(f < r)) continue;
      if (l < f) s.insert(f);
    }
  }

  return s.size();
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
