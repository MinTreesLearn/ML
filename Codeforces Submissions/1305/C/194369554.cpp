#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,avx2,fma,mmx,sse2,sse3,sse4")
#pragma GCC optimization("unroll-loops")
///for pragma could get a runtime/tle too
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define yes "YES"<<endll
#define no "NO"<<endll
#define sp ' '
#define Case(i) cout<<"Case "<<i<<": "
#define endll '\n'
#define ub upper_bound
#define lb lower_bound
#define mod 1000000007
#define M 100005
#define nd node+node
#define left st,(st+en)/2,nd
#define right (st+en)/2+1,en,nd+1
#define sz(v) (int)v.size()
#define mem(x,y) memset(x,y,sizeof(x))
#define uniq(v) v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define rep(i,n) for(int i=0; i<n; i++)
#define reprev(i,n) for(int i=n-1; i>=0; i--)
#define repok(i,n,ok) for(int i=0; i<n && ok; i++)
#define repn(i,n) for(int i=1; i<=n; i++)
#define all(v) v.begin(),v.end()
#define esp 0.000001

void fast(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main(){
    fast();
//    freopen("run_in.txt","r",stdin);
//    freopen("run_out.txt","w",stdout);
    int t=1, tc=0; //cin>>t;
    while(t--){
        ll n, m, ans=1, x;
        cin>>n>>m;
        vector<int>v(n);
        rep(i,n) cin>>v[i];
        if(n>m){
            cout<<0;
            return 0;
        }
        rep(i,n){
            for(int j=i+1; j<n; j++) ans = (ans*abs(v[j]-v[i]))%m;
        }
        cout<<ans;
    }
}

