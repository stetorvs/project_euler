#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 80;

  vector<int> v;

  ifstream f;
  f.open("matrix.txt");
  for (int i = 0; i < in * in; i++) {
    int a;
    f >> a;
    v.push_back(a);
  }
  f.close();

  for (int i = 0; i < in; i++) {
    for (int j = 0; j < in; j++) {
      if (i == 0 && j == 0) continue;
      int left = (j == 0) ? INT_MAX : v[i * in + j - 1];
      int up = (i == 0) ? INT_MAX : v[(i-1) * in + j];
      v[i * in + j] += min(left, up);
    }
  }

  return v.back();
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
