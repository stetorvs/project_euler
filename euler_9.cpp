#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int compute_product()
{
  vector<int> v;

  for (int i = 1; i < 1000; i++)
    for (int j = 1; j < 1000 - i; j++) {
       auto k = 1000 - i - j;
       if (i * i + j * j == k * k) return i * j * k;
    }

  return 0;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
