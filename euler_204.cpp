#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i*i <= n; i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

int compute_count()
{
  vector<int> primes;
  for (int i = 1; i <= 100; i++) {
    if (is_prime(i)) primes.push_back(i);
  }
  constexpr long long N = 1E9;

  int count = 1;
  vector<pair<vector<int>, long long>> st = {{{0}, primes[0]}};
  while (!st.empty()) {
    auto [int_vec, product] = st.back();
    if (product > N) {
      st.pop_back();
      continue;
    }
    ++count;
    if (int_vec.back()+1U == primes.size()) {
      st.pop_back();
    } else {
      st.back().second /= primes[st.back().first.back()];
      st.back().first.back()++;
      st.back().second *= primes[st.back().first.back()];
    }
    int_vec.push_back(int_vec.back());
    st.emplace_back(int_vec, product*primes[int_vec.back()]);
  }
  return count;
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
