#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
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
  const int in = 80;

  vector<int> v;

  ifstream f;
  f.open("matrix.txt");
  for (int i = 0; i < in * in; i++) {
    int a;
    f >> a;
    v.push_back(a);
  }
  f.close();

  vector<int> d(in *in);
  vector<Node> h;

  fill(begin(d), end(d), INT_MAX);

  h.emplace_back(v[0], 0, 0);

  while (!h.empty()) {
    Node n = h.front();
    pop_heap(begin(h), end(h));
    h.pop_back();
    if (n.dist < d[n.x * in + n.y]) {
      d[n.x * in + n.y] = n.dist;
      if (n.x < in - 1) {
        Node t = n;
        t.x++;
        t.dist += v[t.x*in+t.y];
        h.push_back(t);
        push_heap(begin(h), end(h));
      }
      if (n.x > 0) {
        Node t = n;
        t.x--;
        t.dist += v[t.x*in+t.y];
        h.push_back(t);
        push_heap(begin(h), end(h));
      }
      if (n.y < in - 1) {
        Node t = n;
        t.y++;
        t.dist += v[t.x*in+t.y];
        h.push_back(t);
        push_heap(begin(h), end(h));
      }
      if (n.y > 0) {
        Node t = n;
        t.y--;
        t.dist += v[t.x*in+t.y];
        h.push_back(t);
        push_heap(begin(h), end(h));
      }
    }
  }

  return d.back();
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
