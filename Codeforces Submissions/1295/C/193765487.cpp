#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> pos[30];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll T;
    string s,t;
    cin >> T;
    while (T--)
    {
        cin >> s >> t;
        for (ll i=0;i<26;i++)
            pos[i].clear();
        for (ll i=0;i<s.size();i++)
            pos[s[i]-'a'].push_back(i);
        if (!pos[t[0]-'a'].size())
        {
            cout << -1 << "\n";
            continue;
        }
        ll cur=pos[t[0]-'a'][0],ans=1;
        for (ll i=1;i<t.size();i++)
        {
            if (!pos[t[i]-'a'].size())
            {
                ans=-1;
                break;
            }
            auto it=upper_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),cur);
            if (it==pos[t[i]-'a'].end())
            {
                cur=pos[t[i]-'a'][0];
                ans++;
            }
            else
                cur=*it;
        }
        cout << ans << "\n";
    }
    return 0;
}
