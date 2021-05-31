#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>

using namespace std;

int mult_inverse(int a, int n)
{
  int t = 0;
  int new_t = 1;
  int r = n;
  int new_r = a;

  while (new_r != 0) {
    int quotient = r / new_r;
    tie(t, new_t) = make_tuple(new_t, t - quotient * new_t);
    tie(r, new_r) = make_tuple(new_r, r - quotient * new_r);
  }
  if (t < 0) {
    t += n;
  }
  return t;
}

size_t compute_s(int digit, int p1, int p2)
{
  size_t n = mult_inverse(digit % p2, p2) * (p2-p1) % p2;
  return n * digit + p1;
}

size_t compute_sum()
{
  constexpr int MAX = 1'001'000;
  vector<int> primes;

  vector<bool> sieve(MAX);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i < MAX; i++) {
    if (sieve[i] && i > 3) primes.push_back(i);
    for (int j = i * 2; j < MAX; j += i) sieve[j] = false;
  }

  cout << "Found: " << primes.size() << " prime numbers\n";

  size_t sum = 0;
  int digit = 10;
  for (auto it = begin(primes); next(it) != end(primes); ++it) {
    if (*it > 1'000'000) break;
    while (*it > digit) digit *= 10;
    sum += compute_s(digit, *it, *next(it));
  }

  return sum;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
