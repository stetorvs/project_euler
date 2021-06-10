#include <array>
#include <iostream>
#include <numeric>

using namespace std;

long long choose(int n, int r)
{
  int j = n;
  long long choose = 1;
  for (int i = 0; i < r; i++) {
    choose *= j;
    j--;
    choose /= (i+1);
  }
  return choose;
}

double compute_inner_probability(int i)
{
  double prob = 1.;
  double num = 70;
  double good_num = 70 - 10 * (7-i);
  for (int c = 0; c < 20; c++) {
    prob *= good_num / num;
    num -= 1.;
    good_num -= 1.;
  }
  return prob;
}

double compute_probability()
{
  array<double, 8> arr1;
  arr1.fill(0.);
  for (int i = 2; i < 8; i++) {
    arr1[i] = compute_inner_probability(i);
    cout << i << ' ' << arr1[i] << '\n';
  }

  array<double, 8> arr2;
  arr2.fill(0.);
  for (int i = 2; i < 8; i++) {
    double d = arr1[i];
    for (int j = 2; j < i; j++) {
      d += arr1[j] * choose(i, j) * (((i-j) % 2 == 0) ? 1 : -1);
    }
    arr2[i] = d * choose(7, i);
    cout << i << ' ' << arr2[i] << '\n';
  }

  double ev = 0.;
  double sum = 0.;
  for (int i = 1; i < 8; i++) {
    ev += i * arr2[i];
    sum += arr2[i];
  }
  cout << sum << '\n';
  return ev;
}

int main()
{
  cout.precision(10);
  cout << compute_probability() << '\n';

  return 0;
}
