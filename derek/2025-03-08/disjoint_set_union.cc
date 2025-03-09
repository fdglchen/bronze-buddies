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
  int n, m;
  cin >> n >> m;
  vector<int> arr (n, 0);
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  vector<char> ans;
  for (int i = 0; i < m; i++) {
    int z, x, y;
    cin >> z >> x >> y;
    if (z == 1) {
      merge(x, y, arr);
    } else {
      // cout << get(x, arr) << " " << get(y, arr) << endl;
      if (arr[get(x, arr)] == arr[get(y, arr)]) {
        ans.push_back('Y');
      } else {
        ans.push_back('N');
      }
    }
  }
  for (auto it : ans) {
    cout << it << endl;
  }
  // for (int i = 0; i < n; i++) {
  //   cout << arr[i] << endl;
  // }
}