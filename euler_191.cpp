#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct record {
  record(int in_las, int in_ls, long long in_count)
    : las(in_las), ls(in_ls), count(in_count) {}

  int las = 0;
  int ls = 0;
  long long count = 0LL;
};

void append(vector<record>& in, record r)
{
  auto find_it = find_if(begin(in), end(in),
    [r] (record in_r) { return r.las == in_r.las && r.ls == in_r.ls; });
  if (find_it == end(in)) {
    in.emplace_back(r.las, r.ls, r.count);
  } else {
    find_it->count += r.count;
  }
}

vector<record> compute_next(const vector<record>& in)
{
  vector<record> next;

  for (record r : in) {
    record ro = r;
    ro.las = 0;
    append(next, ro);
    record rl = r;
    rl.ls++;
    rl.las = 0;
    if (rl.ls < 2) append(next, rl);
    record ra = r;
    ra.las++;
    if (ra.las < 3) append(next, ra);
  }

  return next;
}

long long compute_count()
{
  vector<record> records = {
    {0, 0, 1LL},
    {1, 0, 1LL},
    {0, 1, 1LL}
  };

  auto cnt_fn = [] (const vector<record>& rs) {
    return accumulate(begin(rs), end(rs), 0LL,
      [] (long long sum, record r) { return sum + r.count; });
  };
  long long cnt = cnt_fn(records);
  cout << "1: " << cnt << '\n';
  for (int i = 2; i <= 30; i++) {
    records = compute_next(records);
    cnt = cnt_fn(records);
    cout << i << ": " << cnt << '\n';
  }

  return cnt;
}

int main()
{
  cout << compute_count() << '\n';

  return 0;
}
