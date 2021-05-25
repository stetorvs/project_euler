#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

using namespace std;

int compute_product()
{
  vector<char> w;

  vector<string> words = {"the", "and"};

  ifstream f("59.txt");
  while (!f.eof()) {
    int a;
    f >> a;
    w.push_back((char)a);
  }
  f.close();

  for (char a = 'a'; a <= 'z'; a++)
    for (char b = 'a'; b <= 'z'; b++)
      for (char c = 'a'; c <= 'z'; c++) {
        string s;
        for (size_t i = 0; i < w.size(); i+= 3) {
          s.push_back(w[i] ^ a);
          if (i+1 < w.size()) s.push_back(w[i+1] ^ b);
          if (i+2 < w.size()) s.push_back(w[i+2] ^ c);
        }
        if (any_of(begin(s), end(s),
            [] (char c) { return c < ' ' || c > 'z'; })) continue;
        if (all_of(begin(words), end(words),
            [&s] (string w) { return s.find(w) != string::npos; })) {
          cout << s << '\n';
          return accumulate(begin(s), end(s)-1, 0);
        }
      }

  return 0;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
