#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long compute_sum()
{
  const int in = 16;
  vector<long long> v;

  for (int i = 0; i < in; i++) {
    if (i == 0) v = {13, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    else v = {v[0] * 13, v[1] * 14 + v[0], v[2] * 14 + v[0], v[3] * 15 + v[1] + v[2], v[4] * 14 + v[8] * 13, v[5] * 15 + v[9] * 14 + v[4] + v[8], v[6] * 15 + v[10] * 14 + v[4] + v[8], v[7] * 16 + v[6] + v[5] + v[10] + v[9] + v[11] * 15, v[8] + v[0], v[9] + v[1], v[10] + v[2], v[11] + v[3]};
    for (auto a : v) cout << a << ' '; cout << '\n';
    printf("%llx\n", accumulate(begin(v), end(v), (long long)0));
  }

  return v[7];
}

int main()
{
  printf("%llX\n", compute_sum());

  return 0;
}
