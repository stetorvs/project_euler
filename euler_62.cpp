#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unsigned long long compute_sum()
{
  const int in = 5;

  unordered_map<string, vector<unsigned long long>> um;

  for (unsigned long long i = 1; true; i++) {
    auto cube = i * i * i;
    string s = to_string(cube);
    sort(begin(s), end(s));
    if (um.find(s) == um.end()) {
      um[s] = {cube};
    } else {
      um[s].push_back(cube);
      if (um[s].size() == in) return um[s].front();
    }
  }
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
