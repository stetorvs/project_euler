#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int msa(vector<int>& v)
{
  int m = 0;
  int rs = 0;

  for (auto i : v) {
    rs += i;
    if (rs < 0) rs = 0;
    m = max(m, rs);
  }

  return m;
}

int compute_product()
{
  int in = 2000;
  vector<long long> v_int;

  for (long long i = 1; i <= 55; i++) {
    v_int.push_back((100003-200003*i+300007*i*i*i)%1000000 - 500000);
  }
  for (long long i = 55; i < in * in; i++) {
    v_int.push_back((v_int[i-24]+v_int[i-55]+1000000)%1000000 - 500000);
  }

  vector<vector<int>> v_in(in);

  for (int i = 0; i < in; i++) {
    copy(begin(v_int)+i*in, begin(v_int)+(i+1)*in, back_inserter(v_in[i]));
  }

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

  int m = 0;

  for (auto cand : v) {
    m = max(msa(cand), m);
  }

  return m;
}

int main()
{
  cout << compute_product() << '\n';

  return 0;
}
