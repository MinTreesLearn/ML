/*
奇偶判断由来：
首先，反转次数为 cnt = n-k+1
若奇偶性相同，则 cnt 为奇数，即 s 的前 k 个字符最终是反的
若奇偶性不同，则最终还是正序的
因为一次反转等价于把前 k 个字符 reverse
*/

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
