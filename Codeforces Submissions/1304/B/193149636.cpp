#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N=100;
string s[MAX_N];
void solve()
{
    ll int n,m,i;
    cin>>n>>m;
    set<string> d;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        d.insert(s[i]);
    }
    vector<string> left,right;
    string mid;
    for( i=0;i<n;i++)
    {
        string t=s[i];
        reverse(t.begin(),t.end());
        if(t==s[i])
            mid=t;
        else if(d.find(t)!=d.end())
        {
            left.push_back(s[i]);
            right.push_back(t);
            d.erase(s[i]);
            d.erase(t);
        }
    }
    cout<<(left.size()*2*m)+mid.size()<<endl;
    for(string x : left) cout<<x;
    cout<<mid;
    reverse(right.begin(), right.end());
    for(string x : right) cout<<x;
    cout<<endl;
}
int main()
{
    ll int tt=1;
    //cin>>tt;
    while(tt--)
        solve();
    return 0;
}
