#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void compute_product()
{
  vector<int> v(10);
  iota(begin(v), end(v), 0);
  for (int i = 0; i < 1E6 - 1; i++)
    next_permutation(begin(v), end(v));

  for_each(begin(v), end(v),
    [] (int i) { cout << i; });
  cout << '\n';
}

int main()
{
  compute_product();

  return 0;
}
