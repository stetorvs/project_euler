#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 1E6;
  vector<int> primes;

  vector<bool> sieve(in);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i < in; i++) {
    if (sieve[i]) primes.push_back(i);
    for (int j = i * 2; j < in; j += i) sieve[j] = false;
  }

  int sum = 0, count = 0;
  while (sum <= in) {
    sum += primes[count++];
  }

  for (int i = count; i >= 0; i--) {
    auto bit = begin(primes);
    auto eit = begin(primes)+i;
    int sum = accumulate(bit, eit, 0);
    do {
      if (sum >= in) break;
      if (sieve[sum]) return sum;
      sum += *eit;
      sum -= *bit;
      eit++;
      bit ++;
    } while (eit != end(primes));
    if (sum < in && sieve[sum]) return sum;
  }
  return 0;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
