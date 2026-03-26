#include<bits/stdc++.h>
using namespace std;
// #define int long long
string f(string &a,string &b)
{
    int n = a.size();
    string res = a;
    int xorr = 'S'^'E'^'T';
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        res[i] = (char)(xorr^a[i]^b[i]);
    }
    return res;
}
void solve()
// int solve()
{
    int n,k;
    cin>>n>>k;
    vector<string> v(n);
    set<string> st;
    for(string &s:v) cin>>s , st.insert(s);
    int ans = 0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
    {
        string res = f(v[i],v[j]);
        if(st.find(res) != st.end()) ans++;
    }
    ans/=3;
    cout<<ans<<endl;
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