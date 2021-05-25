#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>

using namespace std;

int compute_product()
{
  vector<int> ans = {1};
  vector<int> other;

  for (int i = 0; i < 1000; i++) {
    int carry = 0;
    for (auto it = ans.begin(); it != ans.end(); ++it) {
      int sum = carry + 2*(*it);
      carry = sum / 10;
      other.push_back(sum % 10);
    }
    if (carry) other.push_back(carry);
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
