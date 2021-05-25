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

long long compute_product()
{
  int sl = 3;
  int p = 3;
  int n = 5;
  int i = 1 + 4*2;
  while (p * 10 > n) {
    sl += 2;
    for (int j = 0; j < 4; j++) {
      i += (sl-1);
      n++;
      p += is_prime(i);
    }
  }

  return sl;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
