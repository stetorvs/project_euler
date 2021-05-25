#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool is_prime(int n)
{
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0)
      return false;

  return n > 1;
}

int num_digits(int n)
{
  int digits = 0;
  while (n) {
    digits++;
    n /= 10;
  }
  return digits;
}

int replace(int i, int c, int d)
{
  int j = 1;
  int flag = 1;
  int x_max = num_digits(i);
  for (int x = 0; x <= x_max; x++) {
    if (c & flag) {
      int sub = i % (j*10);
      int add = i % j;
      i -= sub;
      i += add;
      i += d * j;
    }
    flag *= 2;
    j *= 10;
  }
  return i;
}

int num_replacements(int i, const unordered_set<int>& primes)
{
  int num_primes = 1;
  int digits = num_digits(i);
  for (int c = 1; c < (1<<digits); c++) {
    int c_num_primes = 0;
    bool self_included = false;
    for (int d = 0; d < 10; d++) {
      int cand = replace(i, c, d);
      if (num_digits(cand) < num_digits(i)) continue;
      bool prime = (cand > i) ? is_prime(cand) : primes.count(cand);
      if (prime) {
        c_num_primes++;
        if (cand == i) self_included = true;
      }
    }
    if (self_included) num_primes = max(num_primes, c_num_primes);
  }
  return num_primes;
}

int find_digit_replacement(int n)
{
  unordered_set<int> primes;
  int i = 2;
  while (true) {
    bool prime = is_prime(i);
    if (prime) {
      primes.insert(i);
    } 
    if (n == num_replacements(i, primes)) return i;
    i++;
    cout << "Checking " << i << '\n';
  }
}

int main()
{
  cout << find_digit_replacement(8) << '\n';

  return 0;
}
