#include <bits/stdc++.h>
#define ll              long long
#define pb              push_back
#define lp(loop,a,b)    for(loop=a;loop<b;loop++)
#define vi(a)           vector<int>a;
#define vl(a)           vector<ll>a;
#define nl              cout<<"\n";
#define cc(a)           cout<<(a?"YES":"NO")<<endl;
#define cs(a)           cout<<(a?"Yes":"No")<<endl;
#define t             int test_case;cin>>test_case;while(test_case--)
#define f               first
#define s               second

using namespace std;


int main()
{
    t
    {
        ll a,b,c,p,m;
        string f;
        ll w[30];
        memset(w,0,sizeof(w));
        cin>>a>>b>>f;
        vl(v);
        lp(p,0,b)
        {
            cin>>c;
            v.pb(c);
        }v.pb(a);
        sort(v.begin(),v.end());
        lp(p,0,a)
        {
            m=v.end()-upper_bound(v.begin(),v.end(),p);
            w[f[p]-'a']+=m;
        }
        lp(p,0,26)
        {
            cout<<w[p]<<" ";
        }
        nl
    }


    return 0;
}
