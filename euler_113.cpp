#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long compute_product()
{
  const int in = 100;

  vector<long long> v(in*10);
  long long sum = 0;

  for (int i = 0; i < in; i++)
    for (int j = 0; j < 10; j++) {
      int index = i * 10 + j;
      if (i == 0) v[index] = 1;
      else v[index] = accumulate(begin(v) + (i-1)*10+j, begin(v) + i*10, (long long)0);
      sum += (j == 0) ? v[index] - 1 : 2 * v[index] - 1;
    }

  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
