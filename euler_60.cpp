#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int concat(int a, int b)
{
  int n = 10;
  while (n < b) n *= 10;
  return a*n + b;
}

bool check(const vector<bool>& sieve, const vector<int>& v, int i)
{
  for (int a : v) {
    int c = concat(a, i);
    if (!sieve[c]) {
      return false;
    }
    c = concat(i, a);
    if (!sieve[c]) {
      return false;
    }
  }
  return true;
}

int compute_set()
{
  constexpr int in = 1E8;
  vector<int> primes;

  vector<bool> sieve(in);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i < in; i++) {
    if (sieve[i] && i != 2 && i < 1E4) primes.push_back(i);
    for (int j = i * 2; j < in; j += i) sieve[j] = false;
  }
  cout << "Done sieve\n";

  // Cheat, assuming high numbers are not prime
  sieve.resize(1E9, false);

  vector<vector<int>> prime_4s;
  for (int i = 0; i < primes.size(); i++) {
    vector<int> v = { primes[i] };
    for (int j = i+1; j < primes.size(); j++) {
      if (!check(sieve, v, primes[j])) continue;
      v.push_back(primes[j]);
      for (int k = j+1; k < primes.size(); k++) {
        if (!check(sieve, v, primes[k])) continue;
        v.push_back(primes[k]);
        for (int l = k+1; l < primes.size(); l++) {
          v.push_back(primes[l]);
          prime_4s.push_back(v);
          v.pop_back();
        }
        v.pop_back();
      }
      v.pop_back();
    }
  }

  auto sort_fn = [] (auto& a, auto& b) {
    return accumulate(begin(a), end(a), 0) > accumulate(begin(b), end(b), 0);
  };

  make_heap(begin(prime_4s), end(prime_4s), sort_fn);
  cout << "Done prime finding quadruplet candidates: " << prime_4s.size() << '\n';

  vector<vector<int>> good_4s;
  while (!prime_4s.empty()) {
    pop_heap(begin(prime_4s), end(prime_4s), sort_fn);
    auto quad = prime_4s.back();
    prime_4s.pop_back();
    int i = quad.back();
    quad.pop_back();
    if (check(sieve, quad, i)) {
      quad.push_back(i);
      good_4s.push_back(quad);
    }
  }

  cout << "Done finding quadruplet sequences: " << good_4s.size() << '\n';

  for (auto& v : good_4s) {
    cout << "Sequence:";
    for (int i : v) {
      cout << ' ' << i;
    }
    cout << '\n';
  }

  int res = 1E8;
  for (auto& v : good_4s) {
    for (int p = v.back() + 1; p < 1E5; p++) {
      if (!sieve[p]) continue;
      if (check(sieve, v, p)) {
        int len = accumulate(begin(v), end(v), p);
        cout << "Found sequence: " << len << '\n';
        res = min(res, len);
        continue;
      }
    }
  }

  return res;
}

int main()
{
  cout << compute_set() << '\n';

  return 0;
}
