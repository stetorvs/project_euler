#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int compute_sum()
{
  const int in = 100;

  vector<int> v(in*in);

  for (int i = 0; i < in; i++) {
    for (int j = 0; j < in; j++) {
      int index = i * in + j;
      if (i == 0) v[index] = 1;
      else if (i > j) v[index] = v[(i-1)*in + j];
      else if (i == j) v[index] = 1 + v[(i-1)*in+j];
      else v[index] = v[index-(i+1)] + v[(i-1)*in+j];
    }
  }

  return v.back()-1;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
