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
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  // ifstream fin("uoj6.in");
  cin >> n >> k;
  vector<double> v;
  double m = 1e18; // numeric_limits<float>::max();
  // cout << m << endl; 
  // int flag = 1;
  for (int i = 0; i < n; i++) {
    double a;
    cin >> a;
    // a = a * 100;
    v.push_back(a);
    // if (a > m) {
    //   m = a;
    // }
    // if (a != 1000000000) {
    //   flag = 0;
    // }
  }
  // if (flag == 1) {
  //   cout << int(k / n) << "000000000";
  //   return 0;
  // }
  double l = 1;
  for (int a = 0; a < 500; a++) {
    double middle = (l + m) / 2;
    double total = 0;
    for (int i = 0; i < n; i++) {
      total = total + (long long)(middle / v[i]);
    }
    // cout << a << " " << total << " " << k << endl;
    if (total >= k) {
      m = middle;
    }
    if (total < k) {
      l = middle;
    }
  }
  double ans = (m + l) / 2.0;
  // ans = floor(ans * 100) / 100;
  // // cout << fixed;
  // // cout << setprecision(2);
  ll aj = ceil(ans);
  cout << aj;
  // cout << ans;
}