#include <iostream>
#include <gmpxx.h>

using namespace std;

int num_digits(mpz_class n)
{
  int digits = 0;
  while (n) {
    digits++;
    n /= 10;
  }
  return digits;
}

mpz_class exponent(int b, int pow)
{
  mpz_class res = 1;
  for (int i = 0; i < pow; i++) {
   res *= b;
  }
  return res;
}

int find_num()
{
  int res = 0;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 25; j++) {
      mpz_class exp = exponent(i, j);
      if (j == num_digits(exp)) {
        cout << exp << ' ' << i << '^' << j << '\n';
        res++;
      }
    }
  }
  return res;
}

int main()
{
  cout << find_num() << '\n';

  return 0;
}
