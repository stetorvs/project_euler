#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>

using namespace std;

void compute_product()
{
  int sum = 0;
  for (int i = 10; i < 100; i++) {
    for (int j = 10; j < 100; j++) {
      if (i%10 == j/10 && i != j) {
        if (fabs((i/10) / (double)(j%10) - i / (double)j) < 0.00001) {
          cout << i << '/' << j << '\n';
        }
      }
    }
  }
}

int main()
{
  compute_product();

  return 0;
}
