#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int compute_product()
{
  vector<int> one = {1};
  vector<int> two = {1};

  int count = 2;
  while (two.size() < 1000) {
    int carry = 0;
    vector<int> three;
    for (size_t i = 0; i < two.size(); i++) {
      int sum = carry + two[i] + (i < one.size() ? one[i] : 0);
      carry = sum / 10;
      three.push_back(sum % 10);
    }
    if (carry) three.push_back(carry);
    one = two;
    two = three;
    count++;
  }

  return count;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
