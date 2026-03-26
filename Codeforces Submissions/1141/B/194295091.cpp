#include <bits/stdc++.h>

using namespace std;
#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
#define clr(d, v) memset(d,v,sizeof(d))
#define ll long long


void file() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    file();
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it: v)cin >> it;
    for (int i = 0; i < n; i++) {
        v.push_back(v[i]);
    }
    int ans = 0;
    int cnt = 0;
    for (auto it: v) {
        if (it == 1)cnt++;
        else cnt = 0;
        ans = max(ans, cnt);

    }
    cout << ans;


}