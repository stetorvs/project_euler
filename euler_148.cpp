#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int triangle (int n)
{
  return n * (n+1)/2;
}

long long compute_sum()
{
  const int in = 1E9;

  vector<int> v;
  int i = in;
  while (i) {
    v.push_back(i%7);
    i /= 7;
  }

  long long sum = 0, pow = 1, prod = 1;
  for (auto a : v) pow *= triangle(7);
  while (!v.empty()) {
    auto a = v.back();
    v.pop_back();
    pow /= triangle(7);
    sum += prod * pow * triangle(a);
    prod *= (a+1);
  }

  return sum;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
