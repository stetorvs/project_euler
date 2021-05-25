#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 1E7;
  const int param = 4;
  vector<int> primes;

  vector<bool> sieve(in);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i < in; i++) {
    if (sieve[i]) primes.push_back(i);
    for (int j = i * 2; j < in; j += i) sieve[j] = false;
  }

  int consec = 0;

  for (int i = 1; i < in; i++) {
    int prime_facs = count_if(begin(primes), begin(primes) + i/2 + 1,
      [&i] (int n) { return i % n == 0; });
    if (prime_facs == param) consec++;
    else consec = 0;
    if (consec == param) return i - param + 1;
  }
  return 0;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
