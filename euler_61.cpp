#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool check(int n)
{
  return (n >= 1000 && (n%100) > 9);
}

int compute_set()
{
  constexpr int N = 6;
  array<vector<int>, N> figurates;
  for (int i = 0; i < 1000; i++) {
    int n = i*(i+1)/2;
    if (n > 9999) break;
    if (check(n)) figurates[0].push_back(n);
  }
  for (int i = 0; i < 1000; i++) {
    int n = i*i;
    if (n > 9999) break;
    if (check(n)) figurates[1].push_back(n);
  }
  for (int i = 0; i < 1000; i++) {
    int n = i*(3*i-1)/2;
    if (n > 9999) break;
    if (check(n)) figurates[2].push_back(n);
  }
  for (int i = 0; i < 1000; i++) {
    int n = i*(2*i-1);
    if (n > 9999) break;
    if (check(n)) figurates[3].push_back(n);
  }
  for (int i = 0; i < 1000; i++) {
    int n = i*(5*i-3)/2;
    if (n > 9999) break;
    if (check(n)) figurates[4].push_back(n);
  }
  for (int i = 0; i < 1000; i++) {
    int n = i*(3*i-2);
    if (n > 9999) break;
    if (check(n)) figurates[5].push_back(n);
  }

  unordered_map<int, vector<int>> edges;
  unordered_set<int> fanins;

  for (int i = 0; i < N; i++) {
    for (int n : figurates[i]) {
      int head = n % 100;
      for (int j = 0; j < N; j++) {
        if (j == i) continue;
        auto begin_it = lower_bound(begin(figurates[j]), end(figurates[j]),
            head*100);
        auto end_it = lower_bound(begin(figurates[j]), end(figurates[j]),
            head*100+99);
        for (auto it = begin_it; it != end_it; ++it) {
          edges[i*10000 + n].push_back(j*10000 + *it);
          fanins.insert(j*10000 + *it);
        }
      }
    }
  }

  for (int n : figurates[5]) {
    if (fanins.count(n + 50000) == 0U) continue;
    vector<tuple<int, int, vector<int>, unordered_set<int>>> stack;
    vector<int> empty;
    unordered_set<int> empty_set;
    stack.emplace_back(n, 5, empty, empty_set);
    while (!stack.empty()) {
      auto [num, group, vec, visited] = stack.back();
      stack.pop_back();
      if (visited.count(group) != 0U) {
        continue;
      }
      vec.push_back(num);
      visited.insert(group);
      int key = group*10000 + num;
      for (int f : edges[key]) {
        if (visited.size() == 6U) {
          if (f == n + 50000) {
            cout << "Found cycle:";
            for (int i : vec) cout << ' ' << i;
            cout << '\n';
            return accumulate(begin(vec), end(vec), 0);
          }
          continue;
        }
        stack.emplace_back(f % 10000, f / 10000, vec, visited);
      }
    }
  }

  return 0;
}

int main()
{
  cout << compute_set() << '\n';

  return 0;
}
