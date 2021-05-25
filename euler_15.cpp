#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long compute_product()
{
  const auto in = 20 + 1;
  vector<long long>v(in * in);

  for (int i = 0; i < in; i++)
    for (int j = 0; j < in; j++) {
      long long sum_left = (i == 0) ? 0 : v[(i-1) * in + j];
      long long sum_right = (j == 0) ? 0 : v[i * in + j - 1];
      if (i == 0 && j == 0) v[0] = 1;
      else v[i * in + j] = sum_left + sum_right;
    }

  return v.back();
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
