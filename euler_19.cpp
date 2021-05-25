#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int compute_product()
{
  vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day = -v[0];
  int sum = 0;
  for (int year = 1900; year <= 2000; year++) {
    for (int month = 0; month < 12; month ++) {
      day += v.at(month);
      if (month == 1 && year % 4 == 0 && year % 400 != 0)
        day++;
      day %= 7;
      if (year > 1900 && day == 6) sum++;
    }
  }
  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
