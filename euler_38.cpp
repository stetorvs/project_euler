#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void extract_digits(vector<int> &v, set<int> &s, int i)
{
  auto size = v.size();
  while(i && v.size() == s.size()) {
    v.push_back(i%10);
    s.insert(i%10);
    i /= 10;
  }
  reverse(begin(v)+size, end(v));
}

void pdm(int i)
{
  vector<int>v;
  set<int>s;

  int a = i;
  while(v.size() < 9 && v.size() == s.size()) {
    extract_digits(v, s, a);
    a += i;
  }
  if (v.size() == 9 && s.size() == 9 && s.find(0) == s.end()) {
    for (auto i : v) cout << i;
    cout << '\n';
  }
}

void compute_product()
{
  pdm(9);
  for (int i = 90; i < 99; i++) {
    pdm(i);
  }
  for (int i = 900; i < 999; i++) {
    pdm(i);
  }
  for (int i = 9000; i < 9999; i++) {
    pdm(i);
  }
}

int main()
{
  compute_product();

  return 0;
}
