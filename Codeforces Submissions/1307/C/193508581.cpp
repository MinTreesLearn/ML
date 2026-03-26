#include<bits/stdc++.h>

using namespace std;

#define int int64_t 
int32_t main() {
    string s;
    cin >> s;
    map<int, int> cnt;
    map<int, int> freq;
    int ans = 0;
    for (char &c: s) {
        int d = c - 'a';
        for (auto[cc, f]: freq) {
            int key = d * 26 + (cc - 'a');
            cnt[key] += f;
            ans = max(ans, cnt[key]);
        }
        ans = max(ans, ++freq[d]);
    }

    cout << ans;
}