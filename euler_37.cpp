#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

vector<int> gen_trunc(int n)
{
  vector<int> v;
  vector<int> ret;

  while (n) {
    ret.push_back(n);
    v.push_back(n%10);
    n /= 10;
  }

  v.pop_back();
  while (!v.empty()) {
    int p = 0;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
      p *= 10;
      p += *it;
    }
    ret.push_back(p);
    v.pop_back();
  }

  return ret;
}

bool is_trunc_prime(int n)
{
  if (!is_prime(n)) return false;
  vector<int> v = gen_trunc(n);

  bool ret = all_of(begin(v), end(v), is_prime);
  return ret;
}

int compute_product()
{
  int sum = 0;
  int count = 0;
  int i = 10;
  for (int i = 10; count < 11; i++) {
    if (is_trunc_prime(i)) {
      count++;
      sum += i;
    }
  }

  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
