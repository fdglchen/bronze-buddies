#include <iostream>
using namespace std;

int binarysearch(int m, int g) {
    int l = 0, r = m, sec = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (m - mid == g) return mid;
        else if (m - mid > g) {
            r = mid - 1;
            sec = mid; 
        } 
        else {
            l = mid + 1;
        }
    }
    return sec;
}

int main() {
    int n, k, m = 0, g;
    cin >> n >> g;
    for (int i = 0; i < n; i++) {
        cin >> k;
        m += k;  
    }
    cout << binarysearch(m, g);
    return 0;
}
