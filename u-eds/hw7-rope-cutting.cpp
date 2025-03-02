#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

bool check(int n, int k, double l, double arr[]){
    int p = 0;
    for (int i = 0; i < n; i++) {
        int new_pieces = (int)(floor(arr[i]/l));
        p += new_pieces;
        if (p >= k) {
            return true;
        }
    }
    return p >= k;
}



double binarysearch(double arr[], int k, int n) {
    double l = 0, r = 100000, ans = 0;
    while (r-l>1e-6) {
        double mid = (l + r) / 2;
        if (check(n, k, mid, arr)) {
            ans = mid; l = mid; 
        } else {
            r = mid;
        }
    }
    return ans;
}

int main() {
    int n, k;
    double x;
    cin >> n >> k;
    double arr[n];
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }
    cout << fixed << setprecision(2) << binarysearch(arr, k, n);
    return 0;
}