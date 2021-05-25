#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>
#include <set>
#include <vector>

using namespace std;

int factorial(int n)
{
  vector<int> v(n);
  iota(begin(v), end(v), 1);
  return accumulate(begin(v), end(v), 1, multiplies<int>());
}

int factorial_sum (int n)
{
  int sum = 0;
  while (n) {
    sum += factorial(n%10);
    n /= 10;
  }

  return sum;
}

int compute_product()
{
  const int in = 1E5;
  int sum = 0;

  for (int i = 3; i < in; i++)
    sum += (factorial_sum(i) == i) ? i : 0;
  return sum;
}

int main()
{
  cout << compute_product() << '\n';;

  return 0;
}
