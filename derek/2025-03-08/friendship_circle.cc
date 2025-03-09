#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <limits>
#include <queue>
#include <iterator>

using namespace std;
using ll = long long;

int get(int x, vector<int> &arr) {
  if (arr[x] == x) {
    return x;
  } else {
    return get(arr[x], arr);
  }
}

void merge(int x, int y, vector<int> &arr) {
  int a = get(x, arr);
  int b = get(y, arr);
  arr[a] = b;
  // cout << get(x, arr) << " " << get(y, arr) < endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a == 1) {
        merge(i, j, v);
      }
    }
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(get(v[i], v));
  }
  cout << s.size();
}