#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

long long compute_product()
{
  unordered_set<long long> pent;
  unordered_set<long long> hex;

  long long c = 0, t = 0;
  for (long long i = 1; c < 3; i++) {
    pent.insert(i*(3*i-1)/2);
    hex.insert(i*(2*i-1));
    t = i*(i+1)/2;
    if (hex.find(t) != hex.end() && pent.find(t) != pent.end()) {
      c++;
      cout << t << '\n';
    }
  }
  return t;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
