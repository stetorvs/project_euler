#include <algorithm>
#include <iostream>
#include <gmpxx.h>

using namespace std;

long long compute_sum()
{
  const int in = 25;
  mpz_class prod;
  mpz_ui_pow_ui(prod.get_mpz_t(), 10, in);
  string ans = prod.get_str(2);

  pair<long long, long long> c = {1,0};

  for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
    if (*it == '0') {
      c = {c.first, c.first+c.second};
    } else {
      c = {c.first+c.second, c.second};
    }
  }

  return c.first;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
