#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int compute_count()
{
  constexpr int in = 1E6;

  vector<int> v(in+1, 0);
  for (int i = 1; i <= in/2; i++) {
    for (int j = i*2; j <= in; j+= i) {
      v[j] += i;
    }
  }

  vector<int> cl_vec(in+1, 0);
  cl_vec[1] = -1;
  for (int i = 2; i <= in; i++) {
    if (cl_vec[i] != 0) continue;
    int next = v[i];
    int len = 1;
    int chain_start = 2;
    unordered_map<int, int> hash = {{i, 1}};
    while (next <= 1E6) {
      if (cl_vec[i] != 0) {
        chain_start = len+1;
        break;
      }
      auto find_it = hash.find(next);
      if (find_it != hash.end()) {
        chain_start = find_it->second;
        break;
      }
      len++;
      hash.emplace(next, len);
      next = v[next];
    }
    if (next > 1E6) chain_start = len + 1;
    for (auto [num, num_len] : hash) {
      if (num_len >= chain_start) {
        cl_vec[num] = len - chain_start + 1;
      } else {
        cl_vec[num] = -1;
      }
    }
  }

  auto max_it = max_element(begin(cl_vec), end(cl_vec),
    [] (int a, int b) {
      return a < b;
  });
  return distance(begin(cl_vec), max_it);
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
