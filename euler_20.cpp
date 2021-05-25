#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int compute_product()
{
  vector<int> ans = {1};
  vector<int> other;

  for (int i = 1; i <= 100; i++) {
    int carry = 0;
    for (auto it = ans.begin(); it != ans.end(); ++it) {
      int sum = carry + i*(*it);
      carry = sum / 10;
      other.push_back(sum % 10);
    }
    while (carry) {
      other.push_back(carry%10);
      carry /= 10;
    }
    ans = other;
    other.clear();
  }

  return accumulate(begin(ans), end(ans), 0);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
