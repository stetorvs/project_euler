#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int popcnt(unsigned i)
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
  vector<unsigned> v;
  for (unsigned u = 0; u < (1 << 10); u++) {
    if (popcnt(u) == 6) v.push_back(u);
  }

  const vector<array<int, 2>> squares = {
    {0, 1}, {0, 4}, {0, 9}, {1, 6}, {2, 5}, {3, 6}, {4, 9}, {6, 4}, {8, 1}
  };

  int cnt = 0;
  for (unsigned u1 : v) {
    bitset<10> b1(u1);
    if (b1.test(6)) b1.set(9);
    if (b1.test(9)) b1.set(6);
    for (unsigned u2 : v) {
      if (u2 < u1) continue;
      bitset<10> b2(u2);
      if (b2.test(6)) b2.set(9);
      if (b2.test(9)) b2.set(6);
      if (std::all_of(begin(squares), end(squares), [&] (auto sq) {
        return (b1.test(sq[0]) && b2.test(sq[1]) || b1.test(sq[1]) && b2.test(sq[0]));
      })) {
        ++cnt;
      }
    }
  }
  return cnt;
}

int main()
{
  cout << compute_num() << '\n';

  return 0;
}
