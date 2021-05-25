#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

vector<int> decompose(int n)
{
  vector<int> v;
  while (n) {
    v.push_back(n%10);
    n /= 10;
  }
  sort(begin(v), end(v));
  return v;
}

int compute_product()
{
  const int in = 1E4;
  vector<int> primes;

  vector<bool> sieve(in);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i < in; i++) {
    if (i >= 1E3 && sieve[i]) primes.push_back(i);
    for (int j = i * 2; j < in; j += i) sieve[j] = false;
  }

  map<vector<int>, vector<int>> lu;

  for (auto i : primes) {
    auto v = decompose(i);
    if (lu.find(v) == lu.end()) lu[v] = {i};
    else lu[v].push_back(i);
  }

  for (auto i : lu) {
    if (i.second.size() > 2) {
      for (auto it = begin(i.second); it != end(i.second) - 2; ++it) {
        for (auto it2 = it + 1; it2 != end(i.second) - 1; ++it2) {
          if (find(it2 + 1, end(i.second), *it + 2 * (*it2 - *it)) != end(i.second)) {
            cout << *it << *it2 << *it + 2 * (*it2 - *it) << '\n';
          }
        }
      }
    }
  }

  return 0;
}

int main()
{
  compute_product();

  return 0;
}
