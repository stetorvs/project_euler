#include <iostream>
#include <gmpxx.h>

using namespace std;

int digit_expansion(int n, int sq)
{
  bool two_digit = (sq >= 10);
  int digit_sum = two_digit ? (sq%10 + sq/10) : sq;
  mpz_class num = n;
  mpz_class div = sq;
  for (int i = 0; i < (two_digit ? 98 : 99); i++) {
    num *= 100;
    div *= 10;
    for (int j = 0; j < 10; j++) {
      ++div;
      if (div * div > num) {
        digit_sum += j;
        --div;
        break;
      }
    }
  }
  cout << n << ": " << div << '\n';
  return digit_sum;
}

int compute_sum()
{
  int sum = 0;

  for (int i = 1; i < 100; i++) {
    int sq = 0;
    for (int j = 1; j <= 10; j++) {
      if (j*j > i) {
        sq = j-1;
        break;
      }
    }
    if (sq*sq == i) continue;
    sum += digit_expansion(i, sq);
  }

  return sum;
}

int main()
{
  cout << compute_sum() << '\n';;

  return 0;
}
