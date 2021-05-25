#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <gmpxx.h>

using namespace std;

bool is_pandigital(const mpz_class num)
{
  ostringstream oss;
  oss << num;
  string st = oss.str();
  if (st.size() < 9) return false;
  bitset<10> digits;
  for (size_t i = 0; i < 9; i++) {
    digits.set(st[i] - '0');
  }

  return (!digits.test(0) && digits.count() == 9);
}

bool is_pandigital(int i)
{
  bitset<10> digits;
  for (int c = 0; c < 9; c++) {
    digits.set(i%10);
    i /= 10;
  }

  return (!digits.test(0) && digits.count() == 9);
}

int compute_k()
{
  int i = 3;
  int f1_i = 1;
  int f2_i = 1;
  mpz_class f1_m = 1;
  mpz_class f2_m = 1;
  for (;; i++) {
    swap(f1_i, f2_i);
    swap(f1_m, f2_m);
    f1_i += f2_i;
    f1_m += f2_m;
    if (is_pandigital(f1_i) && is_pandigital(f1_m)) break;
    f1_i %= 1'000'000'000;
  }
  return i;
}

int main()
{
  cout << compute_k() << '\n';;

  return 0;
}
