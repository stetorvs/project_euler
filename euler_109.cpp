#include <algorithm>
#include <climits>
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>

using namespace std;

bool cond(int sum)
{
  return sum < 100;
}

int compute_product()
{
  int count = 0;
  vector<int> v(20);
  iota(begin(v), end(v), 1);

  vector<int> d;
  for_each(begin(v), end(v), [&d] (int i) { d.push_back(i); d.push_back(3*i); });
  d.push_back(25);
  auto thr = end(d);
  for_each(begin(v), end(v), [&d] (int i) { d.push_back(2*i); });
  d.push_back(50);

  int sum = 0;

  for (auto it = begin(d); it != end(d); ++it) {
    sum += *it;
    if (cond(sum)) count += it >= thr;
    for (auto it2 = it; it2 != end(d); ++it2) {
      sum += *it2;
      if (cond(sum)) count += (it >= thr) + (it2 != it && it2 >= thr);
      for (auto it3 = it2; it3 != end(d); ++it3) {
        sum += *it3;
        if (cond(sum)) count += (it >= thr) + (it2 != it && it2 >= thr) + (it3 != it2 && it3 >= thr);
        sum -= *it3;
      }
      sum -= *it2;
    }
    sum -= *it;
  }

  return count;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
