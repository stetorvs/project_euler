#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

bool is_bool_palindrome(int n)
{
  vector<int> v;
  while (n) {
    v.push_back(n%2);
    n /= 2;
  }
  vector<int> v2 = v;
  reverse(begin(v2), end(v2));
  return v == v2;
}

bool is_palindrome(int n)
{
  string st = to_string(n);
  string st_rev = st;
  reverse(begin(st_rev), end(st_rev));
  return st == st_rev;
}

int compute_product()
{
  vector<int> v(1E6-1);
  iota(begin(v), end(v), 1);

  return accumulate(begin(v), end(v), 0,
    [] (int sum, int n) { return sum + (is_palindrome(n) && is_bool_palindrome(n) ? n : 0); });
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
