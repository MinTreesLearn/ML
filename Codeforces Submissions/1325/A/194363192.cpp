#include<iostream>
#include<queue>
#include <algorithm>
#include "vector"

using namespace std;

void solve() {
    int x;
    cin >> x;
    cout << 1 << ' ' << x-1 << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}