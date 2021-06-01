#include <iostream>

using namespace std;

int popcnt(int i)
{
  int cnt = 0;
  while (i != 0) {
    cnt++;
    i = i & (i-1);
  }
  return cnt;
}

int compute_num()
{
  constexpr int IN = 15;
  constexpr int majority = (IN+2)/2;
  int n = (1 << IN);
  double prob = 0.;
  for (int i = 0; i < n; i++) {
    if (popcnt(i) < majority) continue;
    double prod = 1.;
    int mask = 1;
    int den = 2;
    for (int j = 0; j < IN; j++) {
      if (mask & i) {
        prod *= (1./den);
      } else {
        prod *= (den-1.)/den;
      }
      mask <<= 1;
      den++;
    }
    prob += prod;
  }
  return static_cast<int>(1./prob);
}

int main()
{
  cout << compute_num() << '\n';

  return 0;
}
