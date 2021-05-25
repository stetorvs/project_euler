#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <gmpxx.h>

using namespace std;

bool check(mpz_class m)
{
  vector<int> in(9);
  iota(begin(in), end(in), 1);
  reverse(begin(in), end(in));

  mpz_class sq = m*m;

  for (auto a : in) {
    if (sq % 10 != a) return false;
    if (a != in.back()) sq /= 100;
  }

  return sq == in.back();
}

mpz_class compute_product()
{
  mpz_class l = 10;
  vector<mpz_class> v = {3,7};
  vector<mpz_class> in = {/*1,2,3,4,*/5,6,7,8/*,9*/};
  reverse(begin(in), end(in));

  for (auto m : in) {
    vector<mpz_class> t = v;
    v.clear();
    for (auto s : t) {
      for (mpz_class i = 0; i < 100; i++) {
        mpz_class rt = i * l + s;
        mpz_class sq = rt*rt;
        if (sq / l / 10 % 10 == m) {
          v.push_back(rt);
        }
      }
    }
    l *= 100;
  }

  for (auto m : v) if (check(m)) return m * 10;
  return 0;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
