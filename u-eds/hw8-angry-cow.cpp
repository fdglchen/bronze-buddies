#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(long long n, long long m, long long arr[], long long d) {
    long long prev_shed = 0;
    for (long long i = 1; i < m; i++) {
        long long curr_shed = prev_shed + 1;
        while (curr_shed < n && (arr[curr_shed]-arr[prev_shed] < d)) {
            curr_shed++;
        } if (curr_shed >= n) {
            return false;
        }
        prev_shed = curr_shed;
    }
    return true;
}



int binarysearch(long long arr[], long long m, long long n) {
    long long l = 0, r = 1000000000, ans = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(n, m, arr, mid)) {
            ans = mid; l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n, k, m;
    cin >> n >> m;
    vector<long long> arr;
    for (long long i = 0; i < n; i++) {
        cin >> k;
        arr.push_back(k);  
    }
    sort(arr.begin(), arr.end());
    long long arry[n];
    copy(arr.begin(),arr.end(), arry);
    cout << binarysearch(arry, m, n);
    return 0;
}