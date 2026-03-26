//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define pii pair <int, int>
#define F first
#define S second
#define int int64_t

using namespace std;

const int N = 8e5+5, M = 1e9+7;

mt19937 gen(chrono::system_clock().now().time_since_epoch().count());


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n+=2;
    string s;
    cin >> s;
    char Z = 'z' + 1;
    s = Z + s + Z;
    vector <int> p[26];
    for (int i=1;i<n-1;++i) {
        p[s[i]-'a'].push_back(i);
    }
    int nxt[n],prv[n];
    for (int i=0;i<n;++i) {
        nxt[i] = i+1;
        prv[i] = i-1;
    }
    int ans = 0;
    for (char c=25;c>=0;--c) {
        for(int i:p[c]) {
            if (nxt[i] != -1 && s[prv[i]] == 'a' + c - 1 || s[nxt[i]] == 'a' + c - 1) {
                ans++;
                prv[nxt[i]] = prv[i];
                nxt[prv[i]] = nxt[i];
                nxt[i] = -1;
            }
        }
        reverse(p[c].begin(),p[c].end());
        for(int i:p[c]) {
            if (nxt[i] != -1 && s[prv[i]] == 'a' + c - 1 || s[nxt[i]] == 'a' + c - 1) {
                ans++;
                prv[nxt[i]] = prv[i];
                nxt[prv[i]] = nxt[i];
                nxt[i] = -1;
            }
        }
    }
    cout << ans;
    return 0;
}
