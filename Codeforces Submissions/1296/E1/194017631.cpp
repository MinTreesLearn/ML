#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout<<":["<<x<<"XE]"<<endl;
#define debug2(x,y) cout<<":["<<x<<" "<<y<<"XE]"<<endl;
#define _ ios_base::sync_with_stdio(false);
#define mod 1000000007
#define mod2 998244353
#define inf LLONG_MAX
#define yes cout << "YES\n"
#define yes2 cout << "Yes\n"
#define no cout << "NO\n"
#define no2 cout << "No\n"
#define forn2(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define forn(x,n) for(int i=x;i<=n;i++)



int main()
{_
//    freopen("feast.in", "r", stdin);
//    freopen("feast.out", "w", stdout);
    ll t=1,ca=1;
    //cin>>t;
    ///CHECK FROM HERE***
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<ll>v(n+1,-1);
        for(int i=0;i<n;i++){
            if(v[i]!=-1){
                for(int j=i+1;j<n;j++){
                    if(s[j]<s[i]){
                        v[j]=1-v[i];
                    }
                }
                continue;
            }
            set<ll>st;
            for(int j=i+1;j<n;j++){
                if(s[j]<s[i]){
                    if(v[j]!=-1)st.insert(v[j]);
                }
            }
            //debug(st.size())
            if(st.size()==0){v[i]=0;
                for(int j=i+1;j<n;j++){
                    if(s[j]<s[i]){
                        v[j]=1;
                    }
                }
            }
            else{
                ll z=*st.begin();
                z=1-z;
                v[i]=z;
                for(int j=i+1;j<n;j++){
                    if(s[j]<s[i]){
                        if(v[j]==-1)v[j]=1-z;
                    }
                }
            }
        }
        //forn(0,n-1)debug(v[i])
        ll ok=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(v[i]==v[j]&&s[j]<s[i])ok=0;
            }
        }
        if(ok){
            yes;
            forn(0,n-1)cout<<v[i];

        }
        else no;
    }
}
