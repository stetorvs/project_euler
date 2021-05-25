#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long compute_sum()
{
  const int in = 1E5;

  vector<pair<int, int>> v(in);

  int c = 1;
  for (auto it = begin(v); it != end(v); ++it) {
    it->first = 1;
    it->second = c++;
  }

  int i = 2;
  for (auto it = begin(v)+1; it != end(v); ++it, i++) {
    if (it->first != 1) continue;
    auto ait = it;
    for (auto ait = it; ait < end(v); ait+=i) {
      ait->first *= i;
    }
  }

  sort(begin(v), end(v));

  return v[10000-1].second;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
