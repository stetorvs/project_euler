#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compute_set()
{
  constexpr int in = 1E8;
  vector<int> primes;

  vector<bool> sieve(in);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i < in; i++) {
    if (sieve[i]) primes.push_back(i);
    for (int j = i * 2; j < in; j += i) sieve[j] = false;
  }
  cout << "Done sieve, found " << primes.size() << " prime numbers\n";

  int count = 0;
  for (auto it = begin(primes); it != end(primes); ++it) {
    if (*it > 1E4) break;
    for (auto it2 = it; it2 != end(primes); ++it2) {
      if (*it * *it2 < 1E8) {
        ++count;
      } else {
        break;
      }
    }
  }

  return count;
}

int main()
{
  cout << compute_set() << '\n';

  return 0;
}
