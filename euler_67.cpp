#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 100;

  vector<int> v;

  ifstream f;
  f.open("triangle.txt");
  for (int i = 0; i < in * (in + 1) / 2; i++) {
    int a;
    f >> a;
    v.push_back(a);
  }
  f.close();

  for (int i = in - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      int index = i * (i+1) / 2 + j;
      int l = index + i + 1;
      int r = l + 1;
      v[index] += max(v[l], v[r]);
    }
  }

  return v.front();
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
