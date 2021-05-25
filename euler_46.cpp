#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

int compute_product()
{
  vector<int> p;
  unordered_set<int> sq = {1, 4};

  for (int i = 3; true; i+=2) {
    sq.insert(i*i);
    sq.insert((i+1)*(i+1));
    if (is_prime(i)) {
      p.push_back(i);
      continue;
    }
    bool found = false;
    for (auto n : p) {
      if (sq.find((i - n)/2) != sq.end()) {
        found = true;
        break;
      }
    }
    if (!found) return i;
  }

  return 0;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
