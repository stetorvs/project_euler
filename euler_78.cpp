#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int compute_sum()
{
  const int in = 6E4;
  const int m = 1E6;

  vector<int> v(in);
  fill(begin(v), end(v), 1);

  for (int i = 1; i < in; i++) {
    v[i]++;
    if (v[i] == m) return i+1;
    for (int j = i+1; j < in; j++) {
      v[j] += v[j-i-1];
      v[j] %= m;
    }
  }

  return 0;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
