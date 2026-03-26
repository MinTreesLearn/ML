// LUOGU_RID: 99754622
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int mod=998244353;
const int N=2e5+5;

ll x[N], y[N];

void solve(){
    cin>>x[0]>>y[0];
    ll ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    int tot;
    for(int i=1;;i++){
        __int128_t xx=(__int128_t)ax*x[i-1]+bx;
        __int128_t yy=(__int128_t)ay*y[i-1]+by;
        if(xx<=1e18 && yy<=1e18) x[i]=xx, y[i]=yy;
        else{
            tot=i-1;
            break;
        }
    }
    ll xs,ys,t;
    cin>>xs>>ys>>t;
    int ans=0;
    for(int i=0;i<=tot;i++){
        for(int j=i;j<=tot;j++){
            ll sum=abs(x[i]-xs)+abs(x[i]-x[j]);
            sum+=abs(y[i]-ys)+abs(y[i]-y[j]);
            if(sum<=t) ans=max(ans, j-i+1);
            sum=abs(x[j]-xs)+abs(x[i]-x[j]);
            sum+=abs(y[j]-ys)+abs(y[i]-y[j]);
            if(sum<=t) ans=max(ans, j-i+1);
        }
    }
    cout<<ans<<endl;
}
void init(){
    
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    solve();
    
    return 0;
}