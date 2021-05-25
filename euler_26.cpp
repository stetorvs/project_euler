#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int cycles(int n)
{
  map<int, int> lu;

  int count = 0;
  int rem = 10;
  while (true) {
    if (rem >= n) {
      rem = rem % n;
      if (rem == 0) return 0;
    }
    if (lu.find(rem) != lu.end()) return count - lu[rem];
    lu[rem] = count;
    rem *= 10;
    count++;
  }
}

int compute_product()
{
  const int in = 1000;
  int max_index = 0;
  int max = 0;
  for (int i = in-1; i > 0; i--) {
    if (max > i) break;
    int c = cycles(i);
    if (c > max) {
      max_index = i;
      max = c;
    }
  }
  return max_index;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
