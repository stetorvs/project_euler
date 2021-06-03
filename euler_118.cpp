#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct record {
  record (int lp, int i, int n)
    : last_prime(lp), index(i), num(n) {}
  int last_prime;
  int index;
  int num;
};

size_t compute_count()
{
  constexpr int MAX = 1'000'000'000;

  vector<char> sieve(MAX);
  fill(begin(sieve), begin(sieve)+2, false);
  fill(begin(sieve)+2, end(sieve), true);

  for (int i = 2; i*i < MAX; i++) {
    if (!sieve[i]) continue;
    for (int j = i * 2; j < MAX; j += i) sieve[j] = false;
  }

  cout << "Done sieve\n";

  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int cnt = 0;
  do {
    vector<record> st = { {0, 0, 0} };
    while (!st.empty()) {
      auto [last_prime, index, base_num] = st.back();
      st.pop_back();
      for (; index < v.size(); index++) {
        int num = v[index] + base_num*10;
        base_num = 0;
        while (num < last_prime || index < v.size() && !sieve[num]) {
          num *= 10;
          index++;
          num += v[index];
        }
        if (num > last_prime && index < v.size() && sieve[num]) {
          st.emplace_back(last_prime, index+1, num);
          last_prime = num;
          if (index == v.size()-1) {
            ++cnt;
          }
        }
      }
    }
  } while (next_permutation(begin(v), end(v)));

  return cnt;
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
