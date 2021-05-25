#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

unsigned reverse(unsigned n)
{
  unsigned r = 0;
  while (n != 0) {
    r *= 10;
    r += n % 10;
    n /= 10;
  }
  return r;
}

bool is_odd(unsigned n)
{
  while (n) {
    if (n % 2 == 0) return false;
    n /= 10;
  }
  return true;
}

unsigned compute_product()
{
  const int in = 1E9;

  int s = 0;
  for (unsigned i = 1; i < in; i++) {
    if (i % 10 == 0) continue;
    if (is_odd(i + reverse(i))) s++;
  }

  return s;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
