#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//n is the mid
//m is the desired val
bool check(long long sh, long long wh[], long long n, long long g) {
    long long result = 0;
    for (long long i = 0; i<n; i++) {
        long long w = 0;
        if (wh[i] >= sh) w = wh[i] - sh;
        result += w;
    }
    if (result >= g) return true;
    else return false;
}



int binarysearch(long long arr[], long long s, long long g, long long n) {
    long long l = 0, r = s, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid, arr, n, g)) { ans = mid; l = mid + 1; }
        else r = mid - 1;
    }
    return ans;
}

int main() {
    long long n, k, g;
    cin >> n >> g;
    vector<long long> arr;
    for (long long i = 0; i < n; i++) {
        cin >> k;
        arr.push_back(k);  
    }
    long long s = *max_element(arr.begin(), arr.end());
    long long arry[n];
    copy(arr.begin(),arr.end(), arry);
    cout << binarysearch(arry, s, g, n);
    return 0;
}