#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

const unsigned in = 5;

vector<bool> s(1 << in);
vector<int> v;
int depth = 1;
unsigned val = 0;
unsigned mask = (1 << in) - 1;

void recurse(int i)
{
  depth++;
  val <<= 1;
  val |= i;
  if (!s[val & mask] && depth < (1 << in)) {
    s[val & mask] = true;
    recurse(0);
    recurse(1);
    s[val & mask] = false;
  } else if (!s[val & mask]) {
    v.push_back(val>>(in-1));
    printf("%x\n", val);
  }
  val >>= 1;
  depth--;
}

long long compute_product()
{
  fill(begin(s), end(s), false);
  s[0] = true;
  recurse(1);
  return accumulate(begin(v), end(v), (long long)0);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
