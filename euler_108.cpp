#include <iostream>

using namespace std;

bool satisfies(long long n)
{
  constexpr int N = 1000;
  int count = 0;
  int max_count = n;
  for (long long i = n+1; i <= n*2; i++) {
    if ((i*n) % (i - n) == 0LL) {
      count++;
    } else {
      max_count--;
    }
    if (max_count < N) return false;
  }
  return count >= N;
}

int compute_num()
{
  constexpr int mult = 30;
  for (int i = mult; i < 10'000'000; i+=mult) {
    if (satisfies(i)) return i;
  }
  return 0;
}

int main()
{
  cout << compute_num() << '\n';

  return 0;
}
