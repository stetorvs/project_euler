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
  const int in = 1000;

  int sum = 0;

  vector<int> v(in);
  fill(begin(v), end(v), 2);

  mpz_class num = 1;
  mpz_class den = v.back();
  v.pop_back();

  while (!v.empty()) {
    int b = v.back();
    num = num + b * den;
    auto m = gcd(num, den);
    num /= m;
    den /= m;
    mpz_class nd = num-den;
    string n = nd.get_str();
    string d = den.get_str();
    if (n.size() > d.size()) sum++;
    swap(num, den);
    v.pop_back();
  }

  swap(num, den);

  return sum;
}

int main()
{
  cout << compute_product() << '\n';;

  return 0;
}
