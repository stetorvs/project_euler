#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int compute_product()
{
  auto h = "hundred";
  auto t = "thousand";
  vector<string> n(1001);
  vector<string> init = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
  copy(begin(init), end(init), begin(n));

  n[30] = "thirty";
  n[40] = "forty";
  n[50] = "fifty";
  n[60] = "sixty";
  n[70] = "seventy";
  n[80] = "eighty";
  n[90] = "ninety";

  for (int i = 21; i < 100; i++) {
    n[i] = n[i - i%10] + n[i%10];
  }

  for (int i = 100; i < 1000; i++) {
    n[i] = n[i/100] + h;
    if (i % 100 == 0) continue;
    n[i] += "and" + n[i%100];
  }

  n[1000] = n[1] + t;

  return accumulate(begin(n), end(n), 0,
    [] (int sum, string s) { return sum + (int)s.size(); });
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
