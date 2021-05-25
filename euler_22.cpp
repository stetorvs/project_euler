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

  ifstream f("22.txt");
  while (!f.eof()) {
    string a;
    f >> a;
    if (a.size() > 0) w.push_back(a);
  }
  f.close();

  sort(begin(w), end(w));

  int sum = 0;

  for (size_t i = 0; i < w.size(); i++) {
    sum += (i+1) * 
      accumulate(begin(w[i]), end(w[i]), 0,
        [] (int sum, char c) { return sum + (int)(c - 'A' + 1); });
  }

  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
