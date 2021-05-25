#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

struct LessBySecond
{
    template <typename Lhs, typename Rhs>
    bool operator()(const Lhs& lhs, const Rhs& rhs) const
    {
        return lhs.second < rhs.second;
    }
};

int collatz_len(long long n, unordered_map<long long, int>& map)
{
  auto it = map.find(n);
  if (it != map.end())
    return it->second;
  int result = (n % 2 == 1) ? collatz_len(3*n+1, map) : collatz_len(n/2, map); 
  result++;
  map[n] = result;
  return result;
}

long long compute_product()
{
  unordered_map<long long, int> map = {{1, 1}};

  for (long long i = 2; i < 1E6; i++)
    collatz_len(i, map);

  auto max = max_element(begin(map), end(map), LessBySecond());
  return max->first;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
