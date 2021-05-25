#include <algorithm>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

size_t compute_count()
{
  constexpr int SQRT_LIM = 1E4;
  constexpr int LIM = SQRT_LIM*SQRT_LIM;

  unique_ptr<bitset<LIM>> bs = make_unique<bitset<LIM>>();
  for (int i = 0; i < 10; i++) {
    bs->set(i);
  }
  for (int i = 1; i < SQRT_LIM; i++) {
    int k = 0;
    int palindrome = i;
    int num = 1;
    int x = i;
    while (x != 0) {
      palindrome *= 10;
      k *= 10;
      k += x % 10;
      x /= 10;
      num *= 10;
    }
    bs->set(palindrome + k);
    if (i < SQRT_LIM/10) {
      for (int j = 0; j < 10; j++) {
        bs->set(palindrome * 10 + k + j * num);
      }
    }
  }

  size_t count = 0;
  for (int i = 1; i < SQRT_LIM; i++) {
    int sum = i*i;
    for (int j = i+1; j < SQRT_LIM; j++) {
      sum += j*j;
      if (sum >= LIM) {
        break;
      }
      if (bs->test(sum)) {
        count += sum;
        bs->reset(sum);
      }
    }
  }
  return count;
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
