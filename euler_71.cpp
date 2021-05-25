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
  const int in = 1E6;

  set<Fraction> s;

  for (int i = 3; i <= in; i++) {
    Fraction f((3*i-1)/7, i);
    s.insert(f);
  }

  return (*(--end(s))).num;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
