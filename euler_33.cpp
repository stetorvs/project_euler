#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int gcd(int i, int j)
{
  int a = max(i, j);
  int b = min(i, j);
  if (a % b == 0) return b;
  return gcd(a % b, b);
}

int compute_product()
{
  int num = 1;
  int den = 1;
  int sum = 0;
  for (int i = 10; i < 100; i++) {
    for (int j = 10; j < 100; j++) {
      if (i%10 == j/10 && i != j) {
        if (fabs((i/10) / (double)(j%10) - i / (double)j) < 0.00001) {
          cout << i << '/' << j << '\n';
          num *= i;
          den *= j;
        }
      }
    }
  }

  return den / gcd(num, den);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
