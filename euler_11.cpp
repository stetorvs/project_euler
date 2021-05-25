#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int compute_product()
{
  int in = 20;
  int len = 4;
  vector<vector<int>> v_in;

  ifstream f;
  f.open("11.txt");
  for (int i = 0; i < in; i++) {
    v_in.push_back({});
    for (int j = 0; j < in; j++) {
      int x;
      f >> x;
      v_in[i].push_back(x);
    }
  }
  f.close();

  vector<vector<int>>v;
  // horizontal
  for (int i = 0; i < in; i++) {
    v.push_back({});
    vector<int> &vec = v.back();
    for (int j = 0; j < in; j++) {
      vec.push_back(v_in[i][j]);
    }
  }
  // vertical
  for (int i = 0; i < in; i++) {
    v.push_back({});
    vector<int> &vec = v.back();
    for (int j = 0; j < in; j++) {
      vec.push_back(v_in[j][i]);
    }
  }
  // diagonal up
  for (int i = 0; i < in; i++) {
    v.push_back({});
    vector<int> &vec = v.back();
    for (int j = 0; j < in && i + j < in; j++) {
      vec.push_back(v_in[i+j][j]);
    }
  }
  for (int i = 1; i < in; i++) {
    v.push_back({});
    vector<int> &vec = v.back();
    for (int j = 0; j < in && i + j < in; j++) {
      vec.push_back(v_in[j][i+j]);
    }
  }
  // diagonal down
  for (int i = 0; i < in; i++) {
    v.push_back({});
    vector<int> &vec = v.back();
    for (int j = 0; j < in && i + j < in; j++) {
      vec.push_back(v_in[in-1-i-j][j]);
    }
  }
  for (int i = 1; i < in; i++) {
    v.push_back({});
    vector<int> &vec = v.back();
    for (int j = 0; j < in && i + j < in; j++) {
      vec.push_back(v_in[j][in-1-i-j]);
    }
  }

  int max = 0;

  for (auto it = begin(v); it != end(v); ++it) {
    if ((*it).size() < len) continue;
    for (auto it2 = begin(*it); it2 != end(*it) - len + 1; it2++) {
      max = std::max(max, accumulate(it2, it2+len, 1, multiplies<int>()));
    }
  }

  return max;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
