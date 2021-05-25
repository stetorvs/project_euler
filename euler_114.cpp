#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long compute_sum()
{
  const int in = 50;
  const int m = 3;

  vector<long long> v(m);
  fill(begin(v), end(v), 1);

  for (int i = m; i <= in; i++) {
    long long sum = 1+(i-m+1)*(i-m+2)/2;
    for (int j = m; j < i-m; j++) {
      sum += (j-m+1)*(v[i-j-1]-1);
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
