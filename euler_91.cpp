#include <algorithm>
#include <iostream>

using namespace std;

bool is_right(pair<int, int> p1, pair<int, int> p2)
{
  return (p1.first * p2.first + p1.second * p2.second == 0);
}

int compute_sum()
{
  const int in = 50;

  int sum = 0;

  for (int i = 1; i < (in+1)*(in+1); i++) {
    auto p1 = make_pair(i%(in+1), i/(in+1));
    for (int j = i+1; j < (in+1)*(in+1); j++) {
      auto p2 = make_pair(j%(in+1), j/(in+1));
      bool r = (is_right(p1, p2)
             || is_right(p2, make_pair(p1.first-p2.first,p1.second-p2.second))
             || is_right(p1, make_pair(p2.first-p1.first,p2.second-p1.second)));
      sum += r;
    }
  }

  return sum;
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
