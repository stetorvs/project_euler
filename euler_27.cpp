#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

void compute_product()
{
  int num_primes = 0;
  for (int b = 1; b < 1000; b++) {
    if (!is_prime(b)) continue;
    for (int a = -999; a < 999; a++) {
      int p = b;
      int c;
      for (c = 0; p > 0 && is_prime(p); c++) {
        p = c*c + a*c + b;
      }
      if (c > num_primes) {
        num_primes = c;
        cout << a << ' ' << b << ' ' << c << ' ' << a*b << '\n';
      }
    }
  }
}

int main()
{
  compute_product();

  return 0;
}
