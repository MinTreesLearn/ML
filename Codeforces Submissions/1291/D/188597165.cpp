#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    vector<int>adj[26];
    for(int i=0;i<s.size();i++)
    {
        adj[s[i]-'a'].push_back(i+1);
    }
    int t;cin>>t;while(t--)
    {
        int l,r;cin>>l>>r;
        if(l==r)
        {
            cout<<"Yes\n";
            continue;
        }
        int c=0;
        for(int i=0;i<26;i++)
        {
            if(upper_bound(adj[i].begin(),adj[i].end(),r)-lower_bound(adj[i].begin(),adj[i].end(),l))
            {
                c++;
            }
        }
        if(c>2||s[l-1]!=s[r-1])
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}