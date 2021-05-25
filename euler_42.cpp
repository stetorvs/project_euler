#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

int compute_product()
{
  vector<string> w;

  ifstream f("42.txt");
  while (!f.eof()) {
    string a;
    f >> a;
    w.push_back(a);
  }
  f.close();

  vector<int> v;
  for_each(begin(w), end(w),
    [&v] (string s) { v.push_back(accumulate(begin(s), end(s), 0,
    [] (int sum, char c) { return sum + (int)(c - 'A' + 1); }));
    });

  int s = *max_element(begin(v), end(v));
  unordered_set<int>tris;
  int tri = 1;
  int count = 1;
  while (tri <= s) {
    tris.insert(tri);
    count++;
    tri += count;
  }

  return count_if(begin(v), end(v), [&tris] (int s) { return tris.find(s) != tris.end(); });
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
