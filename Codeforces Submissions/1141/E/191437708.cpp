#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll H,n,najm=1e18,idx=-1;
    cin >> H >> n;
    vector<ll>a(n),p(n),x(n,1e18);
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        if(i) p[i]=p[i-1],x[i]=x[i-1];
        p[i]+=a[i];
        x[i]=min(x[i],p[i]);
    }
    if(p[n-1]>=0)
    {
        if(x[n-1]>-H)
        {
            cout << -1;
            return 0;
        }
        for(ll i=0;i<n;i++)
        {
            if(p[i]>=-H&&p[i]<0)
            {
                cout << 1+i;
                return 0;
            }
        }
    }
    ll l=0,r=LLONG_MAX/abs(p[n-1]),o=-1;
    while(l<=r)
    {
        ll s=(l+r)/2;
        if(s*p[n-1]+x[n-1]<=-H)
        {
            o=s;
            r=s-1;
        }
        else l=s+1;
    }
  //  cout << o << endl;
    ll R=o*p[n-1],ans=n*o;
    l=0,r=n-1,o=-1;
    while(l<=r)
    {
        ll s=(l+r)/2;
        if(x[s]+R<=-H)
        {
            o=s;
            r=s-1;
        }
        else l=s+1;
    }
   // cout << ans << ' ' << o << endl;
    cout << ans+o+1;
    return 0;
}
