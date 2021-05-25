#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compute_sum()
{
  const int in = 2E6;
  vector<int> v;

  for (int i = 1; v.empty() || v.back() < in; i++) {
    v.push_back(i * (i+1)/2);
  }

  int argmin = 0;
  int min = in;

  auto bit = begin(v);
  auto eit = end(v) - 1;
  while (bit < eit) {
    int prod = *bit * *eit;
    if (abs(in - prod) < min) {
      min = abs(in-prod);
      argmin = (bit-begin(v)+1) * (eit-begin(v)+1);
    }
    if (prod > in) eit--;
    else bit++;
  }

  return argmin;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
