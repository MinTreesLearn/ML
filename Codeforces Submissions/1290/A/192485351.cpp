#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>

#define ld long double
#define ll long long
using namespace std;


void solve() {  
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (m <= k) {
        int mx = 0;
        for (int i = 0; i < m; i++) {
            mx = max(mx, max(a[i], a[n-i-1]));
        }
        cout << mx << endl;
        return;
    }

    int v = m - k - 1;

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int mn = 1e9;
        for (int j = 0; j <= v; j++) {
            int b = max(a[i+j], a[i+j+n-m]);
            mn = min(mn, b);
        } 
        ans = max(ans, mn);     
    }


    cout << ans << endl;
}


int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        //cout << "Case #" << i +1 << ": \n";
        solve();
    }
}