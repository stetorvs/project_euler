#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void debug(vector<vector<int>>& v)
{
  for (auto i : v) {
    for (auto j : i) {
      printf("%3d ", j);
    }
    cout << '\n';
  }
}

int compute_product()
{
  const int in = 1001;

  vector<vector<int>> v(in);

  vector<pair<int,int>> dirs = {
      {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
  for (int i = 0; i < in; i++) {
    v[i] = vector<int>(in);
    fill(begin(v[i]), end(v[i]), 0);
  }

  int i = in/2, j = i, dir = 0;
  v[i][j] = 1;

  while (true) {
    pair<int, int>next = {i+dirs[dir].first, j+dirs[dir].second};
    v[next.first][next.second] = v[i][j] + 1;
    i = next.first;
    j = next.second;

    if (v[i][j] == in*in) break;

    int ndir = (dir + 1) % dirs.size();
    next = {i+dirs[ndir].first, j+dirs[ndir].second};
    if (v[next.first][next.second] == 0) dir = ndir;
  }

  return 1 + 4 * accumulate(begin(v[in/2]), begin(v[in/2]) + in/2, 0);
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
