#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int sign(int ax, int ay, int bx, int by)
{
  return -bx*(ay-by)-(ax-bx)*-by;
}

bool in_tri(int ax, int ay, int bx, int by, int cx, int cy)
{
  bool b1, b2, b3;
  b1 = sign(ax, ay, bx, by) < 0;
  b2 = sign(bx, by, cx, cy) < 0;
  b3 = sign(cx, cy, ax, ay) < 0;

  return (b1 == b2) && (b2 == b3);
}

int compute_product()
{
  const int in = 1000;

  int sum = 0;

  ifstream f("triangles.txt");
  for (int i = 0; i < in; i++) {
    int ax, ay, bx, by, cx, cy;
    f >> ax >> ay >> bx >> by >> cx >> cy;
    sum += in_tri(ax, ay, bx, by, cx, cy);
  }

  return sum;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
