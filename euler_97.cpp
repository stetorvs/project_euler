#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

long long compute_product()
{
  const int in = 7830457;
  long long i = 1;
  for (int j = 0; j < in / 10; j++) {
    i *= 1024;
    if (i >= 10000000000) i %= 10000000000;
  }
  for (int j = 0; j < in % 10; j++) {
    i *= 2;
    if (i >= 10000000000) i %= 10000000000;
  }

  i *= 28433;
  i += 1;

  return i % 10000000000;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
