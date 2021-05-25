#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <gmpxx.h>

using namespace std;

mpz_class reverse(mpz_class n)
{
  vector<mpz_class> v;
  while (n != 0) {
    v.push_back(n%10);
    n /= 10;
  }
  mpz_class r = 0;
  for_each(begin(v), end(v),
    [&r] (mpz_class i) { r *= 10; r += i; });
  return r;
}

bool is_palindrome(mpz_class n)
{
  return reverse(n) == n;
}

bool is_lychrel(mpz_class n)
{
  mpz_class cand = n;
  for (mpz_class i = 0; i < 50; i++) {
    cand += reverse(cand);
    if (is_palindrome(cand)) {
      return false;
    }
  }

  return true;
}

mpz_class compute_product()
{
  mpz_class l = 0;
  vector<mpz_class> v(1E4-1);
  iota(begin(v), end(v), 1);

  return count_if(begin(v), end(v), is_lychrel);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
