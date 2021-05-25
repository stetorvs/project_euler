#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void compute_product()
{
  vector<string> v;

  ifstream f;
  f.open("13.txt");
  for (int i = 0; i < 100; i++) {
    string a;
    f >> a;
    v.push_back(a);
  }
  f.close();

  vector<int> sum;

  int carry = 0;

  for (int i = 50 - 1; i >= 0; i--) {
    for (auto it = v.begin(); it != v.end(); ++it) {
      carry += (*it)[i] - '0';
    }
    sum.push_back(carry % 10);
    carry /= 10;
  }

  sum.push_back(carry);

  for_each(sum.rbegin(), sum.rbegin() + 10,
    [](int i) { cout << i; });

  cout << '\n';
}

int main()
{
  compute_product();

  return 0;
}
