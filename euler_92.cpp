#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

int compute_product()
{
  const int in = 1E7;
  vector<int> v(in);
  fill(begin(v), end(v), 0);
  v[1] = 1;
  v[89] = 89;

  for (int i = 2; i < in; i++) {
    vector<int> h = {i};
    int r = v[i];
    while (r == 0) {
      int s = 0;
      int l = h.back();
      while (l) {
        s += (l%10)*(l%10);
        l /= 10;
      }
      h.push_back(s);
      if (s < in) {
        r = v[s];
      }
    }
    for (auto n : h) if (n < in) v[n] = r;
  }

  return count_if(begin(v), end(v), [] (int i) { return i == 89; });
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
