#include<bits/stdc++.h>
using namespace std;
int tt, tc;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(27, INT_MAX);
    freq[0] = INT_MIN;
    reverse(s.begin(), s.end());
    vector<int> ans;

    for (char c : s) {
        int j = c - 'a';
        int x = lower_bound(freq.begin(), freq.end(), j) - freq.begin();
        ans.push_back(x);
        freq[x] = j;
    }
    reverse(ans.begin(), ans.end());
    cout << *max_element(ans.begin(), ans.end()) << "\n";
    for (int c : ans) cout << c << " ";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    tt = 1, tc = 1; // cin >> tt;
    while (tt--) solve(), tc++;
}