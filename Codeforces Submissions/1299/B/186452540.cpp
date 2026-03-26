#include "bits/stdc++.h"

using namespace std;



// #define MULTI_TESTS
// #define FLOAT_PRECISION 13

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        int x1 = x[i] - x[(i + 1) % n];
        int y1 = y[i] - y[(i + 1) % n];
        int x2 = x[(i + n / 2) % n] - x[(i + n / 2 + 1) % n];
        int y2 = y[(i + n / 2) % n] - y[(i + n / 2 + 1) % n];
        if (x1 != -x2 or y1 != -y2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
};

void init() {
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    
    #ifdef FLOAT_PRECISION
        cout << fixed;
        cout.precision(FLOAT_PRECISION);
    #endif
    
    init();
    
    int numTests = 1;
    #ifdef MULTI_TESTS
        cin >> numTests;
    #endif
    for (int testNo = 1; testNo <= numTests; testNo++) {
        solve();
    }
    
    return 0;
}