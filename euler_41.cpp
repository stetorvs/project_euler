#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

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
  vector<int> v = {1};

  while (v.size() < 9) {
    v.push_back(v.size()+1);
    do {
      int n = 0;
      for (auto i : v) {
        n *= 10;
        n += i;
      }
      if (is_prime(n)) cout << n << '\n';
    } while (next_permutation(begin(v), end(v)));
  }
}

int main()
{
  compute_product();

  return 0;
}
