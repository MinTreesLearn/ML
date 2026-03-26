#include<bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int mi = a + b - n + 1,mx = a + b - 1;
    if(mi <= 0) mi = 1;
    if(mi > n) mi = n;
    if(mx > n) mx = n;
    cout<<mi<<' '<<mx<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int tc = 1;
    cin>>tc;
    while (tc--)
    {
        solve();
    }
    return 0;   
}