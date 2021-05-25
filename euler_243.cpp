#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

double res(unsigned long long n)
{
  vector<bool> v(n-1);
  fill(begin(v), end(v), true);
  for (int i = 2; i <= 29; i++)
    if (n % i == 0) {
      auto it = begin(v) + i-1;
      while (it < end(v)) {
        *it = false;
        it += i;
      }
    }

  int p = count_if(begin(v), end(v), [] (bool b) { return b; });
  cout << p << '/' << n-1 << '\n';
  return p / (double) (n-1);
}

unsigned long long compute_product()
{
  double thresh = 15499 / (double) 94744;
  unsigned long long seed = 2*3*5*7*11*13*17*19*23;
  double min = 1.0;

  for (unsigned long long i = seed; true; i += seed) {
    double r = res(i);
    if (r < thresh) return i;
    if (r < min) {
      min = r;
      cout << i << ": " <<  r << '\n';
    }
  }

  return 0;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
