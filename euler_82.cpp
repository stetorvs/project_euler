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

int compute_distance()
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

  vector<int> ds;

  for (int i = 0; i < in; i++) {
    h.emplace_back(v[i*in], 0, i);
  }
  make_heap(begin(h), end(h));

  while (!h.empty()) {
    Node n = h.front();
    pop_heap(begin(h), end(h));
    h.pop_back();
    if (n.dist < d[n.x + n.y * in]) {
      d[n.x + n.y * in] = n.dist;
      if (n.x < in - 1) {
        Node t = n;
        t.x++;
        t.dist += v[t.x+t.y*in];
        h.push_back(t);
        push_heap(begin(h), end(h));
      }
      if (n.y < in - 1) {
        Node t = n;
        t.y++;
        t.dist += v[t.x+t.y*in];
        h.push_back(t);
        push_heap(begin(h), end(h));
      }
      if (n.y > 0) {
        Node t = n;
        t.y--;
        t.dist += v[t.x+t.y*in];
        h.push_back(t);
        push_heap(begin(h), end(h));
      }
    }
  }

  int min_d = INT_MAX;
  for (int i = 0; i < in; i++) {
    min_d = min(min_d, d[i*in+in-1]);
  }
  return min_d;
}

int main()
{
  cout << compute_distance() << '\n';

  return 0;
}
