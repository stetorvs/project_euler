#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int compute_product()
{
  vector<string> w;
  unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  vector<int> v = {0/**/, 1/*I*/, 2/*II*/, 3/*III*/, 2/*IV*/, 1/*V*/, 2/*VI*/, 3/*VII*/, 4/*VIII*/, 2/*IX*/};

  ifstream f("roman.txt");
  while (!f.eof()) {
    string a;
    f >> a;
    if (a.size() > 0) w.push_back(a);
  }
  f.close();

  int sum = 0;

  for (auto s : w) {
    int prev = m[s[0]];
    int i = prev;
    for (auto it = begin(s)+1; it != end(s); ++it) {
      int curr = m[*it];
      if (curr > prev) i -= 2*prev;
      i += curr;
      prev = curr;
    }
    sum += s.size();
    sum -= i / 1000;
    i %= 1000;
    while (i) {
      sum -= v[i%10];
      i /= 10;
    }
  }

  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
