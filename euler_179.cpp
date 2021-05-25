#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compute_sum()
{
  const int in = 1E7-1;

  vector<int> v(in);

  fill(begin(v), end(v), 1);

  int i = 2;
  for (auto it = begin(v)+1; it != end(v); ++it, i++) {
    auto ait = it;
    for (auto ait = it; ait < end(v); ait+=i) {
      (*ait)++;
    }
  }

  int c = 0;

  for (auto it = begin(v)+1; it != end(v); ++it) {
    c += *it == *(it-1);
  }

  return c;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
