#include <algorithm>
#include <iostream>
#include <gmpxx.h>

using namespace std;

mpz_class compute_product()
{
  mpz_class sum = 0;
  for (unsigned i = 99; i > 0; i--)
    for (unsigned j = 99; j > 0; j--) {
      mpz_class r;
      mpz_ui_pow_ui(r.get_mpz_t(), i, j);

      mpz_class c = 0;
      while (r != 0) {
        c += r % 10;
        r /= 10;
      }
      sum = max(sum, c);
    }

  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
