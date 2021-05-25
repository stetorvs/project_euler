#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compute_product()
{
  vector<int> v = {0};

  for (int i = 1; v.size() <= 1E6; i++) {
    vector<int> w;
    int n = i;
    while (n) {
      w.push_back(n%10);
      n/=10;
    }
    copy(w.rbegin(), w.rend(), back_inserter(v));
  }

  return v[1] * v[1E1] * v[1E2] * v[1E3] * v[1E4] * v[1E5] * v[1E6];
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
