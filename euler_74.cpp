#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;

int factorial(int n)
{
  vector<int> v(n);
  iota(begin(v), end(v), 1);
  return accumulate(begin(v), end(v), 1, multiplies<int>());
}

int factorial_sum(int n)
{
  int sum = 0;
  while (n) {
    sum += factorial(n%10);
    n /= 10;
  }

  return sum;
}

int compute_factorial_chains()
{
  int cnt = 0;
  unordered_map<int, int> um;
  for (int i = 1; i < 1E6; i++) {
    int local_cnt = 1;
    int fsum = factorial_sum(i);
    vector<int> v2 = { i };
    auto find_it = find(begin(v2), end(v2), fsum);
    while (find_it == end(v2) && um.count(fsum) == 0U) {
      v2.push_back(fsum);
      fsum = factorial_sum(fsum);
      find_it = find(begin(v2), end(v2), fsum);
    }
    if (find_it != end(v2)) {
      for (auto it = begin(v2); it != find_it; ++it) {
        um[*it] = static_cast<int>(v2.size() - distance(begin(v2), it));
      }
      if (v2.size() == 60) {
        cnt++;
      }
    } else {
      int dist = um[fsum];
      for (auto it = begin(v2); it != end(v2); ++it) {
        um[*it] = static_cast<int>(v2.size() + dist - distance(begin(v2), it));
      }
      if (v2.size() + dist == 60) {
        cnt++;
      }
    }
  }

  return cnt;
}

int main()
{
  cout << compute_factorial_chains() << '\n';;

  return 0;
}
