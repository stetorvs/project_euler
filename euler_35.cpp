#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

vector<int> gen_rot(int n)
{
  deque<int> v;
  int t = n;
  while (t) {
    v.push_back(t%10);
    t /= 10;
  }

  vector<int> ret;

  int p = 0;

  while (p != n) {
    int f = v.front();
    v.pop_front();
    v.push_back(f);
    p = 0;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
      p *= 10;
      p += *it;
    }
    ret.push_back(p);
  }

  return ret;
}

bool is_circular_prime(int n)
{
  if (!is_prime(n)) return false;
  vector<int> v = gen_rot(n);

  bool ret = all_of(begin(v), end(v), is_prime);
  return ret;
}

int compute_product()
{
  const int in = 1E6 - 1;
  vector<long long> v(in);
  iota(begin(v), end(v), 1);

  return count_if(begin(v), end(v), is_circular_prime);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
