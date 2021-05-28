#include <bitset>
#include <iostream>

using namespace std;

void compute_sequence()
{
  bitset<10> bs;
  for (int i = 6; i > 0; i--) {
    bs.set(i);
    for (int j = 9; j > 0; j--) {
      if (i == 6 && j > 5) continue;
      if (bs.test(j)) continue;
      bs.set(j);
      for (int k = 9; k > 0; k--) {
        if (i == 6 && j == 5 && k > 4) continue;
        if (bs.test(k)) continue;
        bs.set(k);
        int sum = i + j + k;
        for (int l = 9; l >= 0; l--) {
          int l2 = (l == 0) ? 10 : l;
          if (l2 < i) continue;
          if (bs.test(l)) continue;
          int m = sum - l2 - k;
          if (m > 9 || m < 1) continue;
          if (bs.test(m) || m == l) continue;
          bs.set(l);
          bs.set(m);
          for (int n = 9; n >= 0; n--) {
            int n2 = (n == 0) ? 10 : n;
            if (n2 < i) continue;
            if (bs.test(n)) continue;
            int o = sum - n2 - m;
            if (o > 9 || o < 1) continue;
            if (bs.test(o) || o == n) continue;
            bs.set(n);
            bs.set(o);
            for (int p = 9; p >= 0; p--) {
              int p2 = (p == 0) ? 10 : p;
              if (p2 < i) continue;
              if (bs.test(p)) continue;
              int q = sum - p2 -o;
              if (q > 9 || q < 1) continue;
              if (bs.test(q) || q == p) continue;
              int r2 = sum - q - j;
              int r = (r2 == 10) ? 0 : r2;
              if (r2 < i) continue;
              if (r2 > 10 || r2 < 1) continue;
              if (bs.test(r) || r == p || r == q) continue;
              cout << i << j << k << l2 << k << m << n2 << m << o << p2 << o << q << r2 << q << j << '\n';
              return;
            }
            bs.reset(o);
            bs.reset(n);
          }
          bs.reset(m);
          bs.reset(l);
        }
        bs.reset(k);
      }
      bs.reset(j);
    }
    bs.reset(i);
  }
}

int main()
{
  compute_sequence();

  return 0;
}
