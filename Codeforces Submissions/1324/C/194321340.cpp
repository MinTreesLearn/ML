#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N=2e5+20;
int t, cnt, ans;
string s;
void solve()  {
    cin >> s;
    ans=0;
    cnt=0;
    for(int i=0; i < s.size(); i++) {
        if(s[i]=='L') cnt++;
        else cnt=0;
        ans=max(ans, cnt);
    }
    cout << ans+1;
}
int main()
{
    cin >> t;
    while(t--)
    {
        solve();
        cout << '\n';
    }
}
