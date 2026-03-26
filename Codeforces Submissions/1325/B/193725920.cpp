#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        unordered_set<int> ue;
        int n;
        cin >> n;
        while (n--) {
            int v;
            cin >> v;
            ue.insert(v);
        }
        cout << ue.size() << "\n";
    }
}
