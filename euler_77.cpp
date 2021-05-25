#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

int compute_sum()
{
  const int in = 1E3;
  const int lim = 5E3;

  vector<int> v(in);
  fill(begin(v), end(v), is_prime(1));

  for (int i = 1; i < in; i++) {
    if (!is_prime(i+1)) continue;
    v[i]++;
    if (v[i] >= lim) return i+1;
    for (int j = i+1; j < in; j++) {
      v[j] += v[j-i-1];
    }
  }

  return v.back();
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
