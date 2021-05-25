#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>

using namespace std;

long long compute_sum()
{
  const int in = 20;

  map<long long, long long> m;
  for (int i = 0; i < 1E3; i++) {
    if (i%10 + i/10%10 + i/100 < 10) {
      m[i] = 1;
    } else {
      m[i] = 0;
    }
  }

  for (int i = 3; i < in; i++) {
    cout << i << ' ' << accumulate(m.find(100), end(m), (long long)0, [] (long long sum, pair<long long, long long> n) { return sum + n.second; }) << '\n';
    auto pm = m;
    for (int i = 0; i < 1E3; i++) {
      m[i] = 0;
      if (i%10 + i/10%10 + i/100 < 10) {
        int k = (i * 10) % 1000;
        for (int j = k; j < k+10; j++) {
          m[i] += pm[j];
        }
      }
    }
  }

  return accumulate(m.find(100), end(m), (long long)0, [] (long long sum, pair<long long, long long> n) { return sum + n.second; });
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
