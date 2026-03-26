#include <iostream>

using namespace std;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans = 1;
    string res = s;

    for(int i=2; i<=n; i++) {
        string t = s.substr(i-1);
        if((i&1) == (n&1)) {
            for(int j=i-2; j>=0; j--) t += s[j];
        } else {
            for(int j=0; j<=i-2; j++) t += s[j];
        }
        if(t < res) {
            ans = i;
            res = t;
        }
    }
    cout << res << '\n' << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
