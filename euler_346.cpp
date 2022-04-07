#include <iostream>
#include <numeric>
#include <unordered_set>

using namespace std;

long long compute_sum()
{
  unordered_set<long long> us = {1};
  for (long long i = 2; i < 1'000'000LL; i++) {
    long long pow = i * i;
    long long rep_sum = 1 + i + pow;
    while (rep_sum <= 1'000'000'000'000LL) {
      us.insert(rep_sum);
      pow *= i;
      rep_sum += pow;
    }
  }

  return accumulate(begin(us), end(us), 0LL);
}

int main()
{
  cout << compute_sum() << '\n';

  return 0;
}
