#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int compute_product()
{
  vector<double> v;

  ifstream f("base_exp.txt");
  while (!f.eof()) {
    int a, b;
    f >> a >> b;
    v.emplace_back(b*log(a));
  }
  f.close();

  return max_element(begin(v), end(v)) - begin(v) + 1;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
