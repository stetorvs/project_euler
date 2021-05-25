#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long compute_colour(int m)
{
  const int in = 50;

  vector<long long> v(m);
  fill(begin(v), end(v), 0);

  for (int i = m; i <= in; i++) {
    long long sum = i - m + 1;
    for (int j = m; j < i-m+1; j++) {
      sum += v[i-j];
    }
    v.push_back(sum);
    cout << i << ' ' << sum << '\n';
  }

  return v.back();
}

long long compute_sum()
{
  return compute_colour(2) + compute_colour(3) + compute_colour(4);
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
