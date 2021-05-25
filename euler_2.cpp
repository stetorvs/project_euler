#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int compute_sum()
{
  vector<int> v = {1, 2};
  while (v.back() < 4E6) {
    v.push_back(v.back() + *(end(v) - 2));
  }

  return accumulate(begin(v), end(v), 0,
    [] (int sum, int v) {return sum + (v & 1 ? 0 : v); });
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
