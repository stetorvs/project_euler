#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long compute_sum()
{
  const int in = 50;
  const int m1 = 2, m2 = 3, m3 = 4;

  vector<long long> v(m1);
  fill(begin(v), end(v), 1);

  for (int i = m1; i <= in; i++) {
    long long sum = 1+i-m1+1;
    if (i >= m2) sum += i-m2+1;
    if (i >= m3) sum += i-m3+1;
    for (int j = m1; j < i-m1+1; j++) {
      sum += v[i-j]-1;
    }
    for (int j = m2; j < i-m1+1; j++) {
      sum += v[i-j]-1;
    }
    for (int j = m3; j < i-m1+1; j++) {
      sum += v[i-j]-1;
    }
    v.push_back(sum);
    cout << i << ' ' << sum << '\n';
  }

  return v.back();
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
