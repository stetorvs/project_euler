#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long choose(int n, int r)
{
  int j = n;
  long long choose = 1;
  for (int i = 0; i < r; i++) {
    choose *= j;
    j--;
    choose /= (i+1);
  }
  return choose;
}

long long compute_product()
{
  const int in = 26;

  vector<long long> v;

  int prev = 0;
  for (long long i = 1; i <= in; i++) {
    prev = prev*2 + i-1;
    v.push_back(choose(in, i) * prev);
    cout << i << ' ' << v.back() << '\n';
  }

  return *max_element(begin(v), end(v));
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
