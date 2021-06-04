#include <cmath>
#include <iostream>

using namespace std;

int compute_count()
{
  constexpr long long N = 1'000'000;

  int count = 0;
  for (long long i = 3; i*i - (i-2)*(i-2) <= N; i++) {
    if (i * i <= N) {
      count += (i-1)/2;
      continue;
    }
    double d = sqrt((double)i*(double)i-(double)N);
    int cd = (int)(ceil(d-1));
    count += (i - cd - 1) / 2;
  }
  return count;
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
