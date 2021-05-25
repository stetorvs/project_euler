#include <algorithm>
#include <iostream>
#include <vector>
#include <gmpxx.h>

using namespace std;

mpz_class gcd (mpz_class a, mpz_class b)
{
  mpz_class M = max(a, b);
  mpz_class m = min(a, b);
  if (M % m == 0) return m;
  else return gcd (M % m, m);
}

mpz_class compute_product()
{
  const int in = 100;

  vector<int> v = {2};
  while (v.size() < in) {
    v.push_back(1);
    if (v.size() < in) v.push_back((v.size()/3 + 1)* 2);
    if (v.size() < in) v.push_back(1);
  }

  mpz_class num = 1;
  mpz_class den = v.back();
  v.pop_back();

  while (!v.empty()) {
    int b = v.back();
    num = num + b * den;
    swap(num, den);
    v.pop_back();
    auto m = gcd(num, den);
    num /= m;
    den /= m;
  }

  swap(num, den);

  mpz_class sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }

  return sum;
}

int main()
{
  cout << compute_product() << '\n';;

  return 0;
}
