#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 1000;
  vector<int> v(in+1);
  fill(begin(v), end(v), 0);

  for (int i = 1; i <= in/2; i++) {
    for (int j = i+1; j <= in/2; j++) {
      int sq = i*i+j*j;
      int c = sqrt(sq);
      if (c*c == sq && i+j+c <= in) v[i+j+c]++;
    }
  }

  return max_element(begin(v), end(v)) - begin(v);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
