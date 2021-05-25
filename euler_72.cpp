#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long compute_sum()
{
  const int in = 1E6;

  vector<int> v(in-1);

  fill(begin(v), end(v), 1);

  int i = 2;
  for (auto it = begin(v); it != end(v); ++it, i++) {
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

  return accumulate(begin(v), end(v), (long long)0);
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
