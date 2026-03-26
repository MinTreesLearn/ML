#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int, int> mp; int maxi=0;
    int n; cin>>n;
    for (int i=0; i<n; i++)
    {
        int u; cin>>u;
        mp[i-u]+=u;
        if (mp[i-u]> maxi) maxi=mp[i-u];
    }
    cout <<maxi <<endl;

}