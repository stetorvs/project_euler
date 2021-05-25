#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 1E4;

  unordered_set<int> pent;

  for (int i = 1; i < in; i++) {
    pent.insert(i*(3*i-1)/2);
  }

  vector<int> v;

  for (auto it = begin(pent); it != end(pent); ++it) {
    for (auto it2 = it; it2 != end(pent); ++it2) {
      int sum = *it + *it2;
      int diff = abs(*it2 - *it);
      if (pent.find(sum) != pent.end() && pent.find(diff) != pent.end()) {
        v.push_back(diff);
      }
    }
  }

  return *min_element(begin(v), end(v));
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
