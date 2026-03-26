#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define repin rep(i,0,n)
#define di(a) ll a;cin>>a;
#define sin string s;cin>>s;
#define dia di(a)
#define dib di(b)
#define dic di(c)
#define dix di(x)
#define diy di(y)
#define diz di(z)
#define dik di(k)
#define din di(n)
#define dim di(m)
#define diq di(q)
#define endl '\n'
#define precise(i) cout<<fixed<<setprecision(i)
#define V vector<ll>
#define pb push_back
#define M map<ll,ll>
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' ';
#define vpii vector<pair<ll,ll>>
#define all(x) x.begin(),x.end()
#define back(x) x.rbegin(),x.rend()
#define MOD 1000000007
#define db double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N =998244353;


int main(){
    fastio;
    
    ll T=1;
    // cin>>T;
    // int ogt=0;
    while(T--){
        // ogt++;
        din;
        sin;
        ll ct=0,l,r;
        ll ans=0;
        for (int i = 0; i < n; ++i)
        {
            if(s[i]=='(') ct++;
            else ct--;

            if(ct<0){
                l=i;
                i++;
                while(i<n && ct<0){
                    if(s[i]=='(') ct++;
                    else ct--;
                    i++;
                }
                i--;
                r=i;
                // cout<<i<<' '<<ct<<endl;
                ans+=r-l+1;
            }
        }

        if(ct!=0) cout<<"-1\n";
        else cout<<ans<<endl;




                
    }
    return 0;
}   