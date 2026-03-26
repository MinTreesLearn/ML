#include<bits/stdc++.h>
using namespace std;
// #define int long long
void solve()
// int solve()
{
    int n;cin>>n;
    vector<int> v(n);
    for(int &i:v) cin>>i;
    if(n==1) {cout<<v[0]<<endl;return;}
    vector<int> p(n),s(n);
    p[0] = ~v[0];
    s[n-1]=~v[n-1];
    for(int i=1;i<n;i++)
    {
        p[i] = p[i-1]&(~v[i]);
        s[n-i-1] = s[n-i]&(~v[n-i-1]);
    }
    int ans = INT_MIN;
    int mx;
    for(int i=0;i<n;i++)
    {
        int crans;
        if(i==0) crans = s[1]&v[i];
        else if(i==n-1) crans = p[n-2]&v[i];
        else crans = p[i-1]&v[i]&s[i+1];
        if(ans < crans)
        {
            mx = i;
            ans = crans;
        }
    }
    cout<<v[mx]<<" ";
    for(int i=0;i<n;i++)
    if(i!=mx) cout<<v[i]<<" ";
    cout<<endl;
    
    
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
        // cout<<solve()<<endl;
    }
    return 0;
}