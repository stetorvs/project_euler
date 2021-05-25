#include <algorithm>
#include <climits>
#include <iostream>
#include <fstream>

using namespace std;

bool is_non_bouncy (int n)
{
  bool ascending = true, descending = true;

  int prev = n % 10;

  while (n) {
    int curr = n % 10;
    if (curr < prev) ascending = false;
    else if (curr > prev) descending = false;
    if (!ascending && !descending) return false;
    prev = curr;
    n /= 10;
  }

  return true;
}

int compute_product()
{
  int i = 0;

  const int in = 99;

  int non_bouncy = 0;

  while (non_bouncy * 100 >= i * (100 - in)) {
    i++;
    if (is_non_bouncy(i)) non_bouncy++;
  }

  return i - 1;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
