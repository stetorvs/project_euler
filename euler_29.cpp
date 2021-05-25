#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

size_t compute_product()
{
  const int in = 100;

  set<pair<int, int>> s;
  map<int, pair<int,int>> m;

  for (int i = 2; i <= in; i++) {
    int count = 1;
    int power = i;
    if (m.find(i) == m.end()) {
      while (power <= in) {
         m[power] = {i, count};
         power *= i;
         count++;
      }
    }
    int base = m[i].first;
    int mult = m[i].second;
    for (int j = 2; j <= in; j++) {
      s.insert({base, j * mult});
    }
  }

  return s.size();
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
