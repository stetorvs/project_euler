#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Node {
  public:
    int dist;
    int x, y;

    Node() : dist(INT_MAX), x(0), y(0) {}
    Node(int dist, int x, int y) : dist(dist), x(x), y(y) {}
    bool operator < (const Node& n) {
      return this->dist > n.dist;
    }
};


int compute_product()
{
  const int in = 40;

  vector<int> v;

  ifstream f;
  f.open("network.txt");
  for (int i = 0; i < in * in; i++) {
    int a;
    f >> a;
    v.push_back(a);
  }
  f.close();

  int sum = accumulate(begin(v), end(v), 0) / 2;
  int inf = sum+1;

  int mst = 0;

  for (auto it = begin(v); it != end(v); ++it) {
    if (*it == 0) *it = inf;
  }

  vector<bool> d(in);
  fill(begin(d), end(d), false);
  vector<Node> h;

  auto it = min_element(begin(v), end(v));

  int index = it - begin(v);
  int i = index / in;
  int j = index % in;

  h.emplace_back(v[index], i, j);

  while (!h.empty()) {
    Node n = h.front();
    pop_heap(begin(h), end(h));
    h.pop_back();
    if (d[n.x] && d[n.y]) continue;

    mst += n.dist;
    d[n.x] = true;
    d[n.y] = true;
    for (i = 0; i < in; i++) {
      if(d[i]) continue;
      index = i * in + n.y;
      if (v[index] == inf) continue;
      h.emplace_back(v[index], i, n.y);
      push_heap(begin(h), end(h));
    }
    for (j = 0; j < in; j++) {
      if(d[j]) continue;
      index = n.x * in + j;
      if (v[index] == inf) continue;
      h.emplace_back(v[index], n.x, j);
      push_heap(begin(h), end(h));
    }
  }

  return sum-mst;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
