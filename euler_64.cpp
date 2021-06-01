#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct record {
  record(int in_integer, int in_neg_num, int in_den)
    : integer(in_integer), neg_num(in_neg_num), den(in_den) {}
  int integer = 0;
  int neg_num = 0;
  int den = 0;

  bool operator==(const record& other) const {
    return integer == other.integer && neg_num == other.neg_num
      && den == other.den;
  }
  bool operator!=(const record& other) const {
    return !(*this == other);
  }
};

int gcd(int i, int j)
{
  int a = max(i, j);
  int b = min(i, j);
  if (a % b == 0) return b;
  return gcd(a % b, b);
}

bool is_odd_period(int n, int sqrt, int rem)
{
  // (sqrt(n) + sqrt) / rem => integer + (sqrt(n)-neg_num)/rem
  int neg_num = -sqrt;
  int integer = 0;
  while (neg_num < 0 || neg_num * neg_num < n) {
    ++integer;
    neg_num += rem;
  }
  --integer;
  neg_num -= rem;
  record r(integer, neg_num, rem);
  vector<record> records;
  auto find_it = end(records);
  while (find_it == end(records)) {
    records.push_back(r);
    int new_num = rem;
    int new_den = n - neg_num * neg_num;
    int multiple = gcd(new_num, new_den);
    new_num /= multiple;
    rem = new_den / multiple;
    neg_num = -neg_num;
    integer = 0;
    while (neg_num < 0 || neg_num * neg_num < n) {
      ++integer;
      neg_num += rem;
    }
    --integer;
    neg_num -= rem;
    r = record(integer, neg_num, rem);
    find_it = find(begin(records), end(records), r);
  }
  return (distance(find_it, end(records)) % 2U) == 1U;
}

int compute_count()
{
  int cnt = 0;
  int sqrt = 0;
  for (int i = 1; i <= 10'000; i++) {
    if ((sqrt+1)*(sqrt+1) <= i) ++sqrt;
    if (sqrt * sqrt == i) continue;
    int rem = i - sqrt*sqrt;
    if (is_odd_period(i, sqrt, rem)) {
      ++cnt;
    }
  }
  return cnt;
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
