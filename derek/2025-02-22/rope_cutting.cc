#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  ifstream fin("uoj6.in");
  fin >> n >> k;
  vector<double> v;
  double m = 0;
  for (int i = 0; i < n; i++) {
    double a;
    fin >> a;
    a = a * 100;
    v.push_back(a);
    if (a > m) {
      m = a;
    }
  }
  double l = 1;
  for (int a = 0; a < 250; a++) {
    double middle = (l + m) / 2;
    int total = 0;
    for (int i = 0; i < n; i++) {
      total = total + (v[i] / middle);
    }
    if (total >= k) {
      l = middle;
    }
    if (total < k) {
      m = middle;
    }
  }
  double ans = (m + l) / 200.0;
  ans = floor(ans * 100) / 100;
  cout << fixed;
  cout << setprecision(2);
  cout << ans;
}