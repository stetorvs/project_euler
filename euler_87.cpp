#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

size_t compute_count()
{
  constexpr int MAX = 50'000'000;
  constexpr int max_prime = 8000;
  vector<int> primes;

  vector<bool> sieve(max_prime);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i < max_prime; i++) {
    if (sieve[i]) primes.push_back(i);
    for (int j = i * 2; j < max_prime; j += i) sieve[j] = false;
  }

  int max_square = 0, max_cube = 0, max_fourth = 0;
  for (int i = 1; i < max_prime; i++) {
    if (!sieve[i]) continue;
    if (i*i > MAX && max_square == 0) {
      max_square = i;
      break;
    }
    if (i*i*i > MAX && max_cube == 0) {
      max_cube = i;
    }
    if (i*i*i*i > MAX && max_fourth == 0) {
      max_fourth = i;
    }
  }

  cout << max_square << ' ' << max_cube << ' ' << max_fourth << '\n';

  bitset<MAX> bs;
  for (int i : primes) {
    if (i >= max_fourth) break;
    for (int j : primes) {
      if (j >= max_cube) break;
      int presum = i*i*i*i + j*j*j;
      if (presum >= MAX) break;
      for (int k : primes) {
        if (k >= max_square) break;
        int sum = presum + k*k;
        if (sum >= MAX) break;
        bs[sum] = true;
      }
    }
  }

  return bs.count();
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
