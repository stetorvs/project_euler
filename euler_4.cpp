#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool is_palindrome(int n)
{
  string st = to_string(n);
  string st_rev = st;
  reverse(begin(st_rev), end(st_rev));
  return st == st_rev;
}

int compute_product()
{
  vector<int> v;

  for (int i = 1; i < 1000; i++)
    for (int j = i; j < 1000; j++) {
      auto prod = i * j;
      if (is_palindrome(prod)) v.push_back(prod);
    }

  return *max_element(begin(v), end(v));
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
