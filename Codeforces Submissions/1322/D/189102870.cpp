#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define sz(a) ((int)a.size())

const int maxn=2005;
int n,m,a[maxn],w[maxn],c[maxn*2],dp[maxn][1<<11],maxx[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> a[i],a[i]--;
    for(int i=0; i<n; ++i) cin >> w[i];
    for(int i=0; i<n+m; ++i) cin >> c[i];
    for(int i=0; i<m; ++i){
        maxx[i]=-1e9;
        for(int s=0; s<(1<<11); ++s) dp[i][s]=-1e9;
    }
    for(int i=n-1; i>=0; --i){
        int ndp[1<<11];
        for(int s=0; s<(1<<11); ++s) ndp[s]=-1e9;
        ndp[1]=c[a[i]]-w[i];
        for(int j=0; j<=a[i]; ++j){
            if(j+11<a[i]){
                ndp[1]=max(ndp[1],maxx[j]+c[a[i]]-w[i]);
                continue;
            }
            for(int s=0; s<(1<<11); ++s){
                int ns=(s>>(a[i]-j))+1;
                int val=dp[j][s]-w[i];
                for(int k=a[i]; k<=a[i]+__builtin_ctz(ns); ++k) val+=c[k];
                ndp[ns]=max(ndp[ns],val);
            }
        }
        for(int s=0; s<(1<<11); ++s){
            dp[a[i]][s]=max(dp[a[i]][s],ndp[s]);
            maxx[a[i]]=max(maxx[a[i]],dp[a[i]][s]);
        }
    }
    int res=0;
    for(int i=0; i<m; ++i) for(int s=0; s<(1<<11); ++s) res=max(res,dp[i][s]);
    cout << res << "\n";
}