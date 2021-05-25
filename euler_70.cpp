#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long compute_sum()
{
  const int in = 1E7;

  vector<int> v(in);

  fill(begin(v), end(v), 1);

  int i = 2;
  for (auto it = begin(v)+i; it != end(v); ++it, i++) {
    if (*it != 1) continue;
    auto ait = it;
    int j = 1;
    for (auto ait = it; ait < end(v); ait+=i, j++) {
      *ait *= (i-1);
      int k = j;
      while (k) {
        if (k % i == 0) {
          *ait *= i;
          k /= i;
        } else break;
      }
    }
  }

  int argmax = 0;
  double max = 0.f;
  for (int i = 2; i < in; i++) {
    long long ii = i, ti = v[i];
    double r = ti / (double) ii;
    if (r < max) continue;
    vector<int> iv, tv;
    while (ii) {
      iv.push_back(ii%10);
      ii /= 10;
    }
    while (ti) {
      tv.push_back(ti%10);
      ti /= 10;
    }
    sort(begin(iv), end(iv));
    sort(begin(tv), end(tv));
    if (iv == tv) {
      argmax = i;
      max = r;
    }
  }

  return argmax;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
