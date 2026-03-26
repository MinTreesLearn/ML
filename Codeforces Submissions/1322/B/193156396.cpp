#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef pair<int,int> PII;
typedef long long LL;
const int INF=0x3f3f3f3f;
const long long LNF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
const int N=400010,M=N<<1;
inline int read(){ 
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}

int n;
int a[N],b[N];

bool check(int x){
    for(int i=1;i<=n;++i)b[i]=a[i]%(1<<(x+1));
    int l1=1<<x,r1=(1<<(x+1))-1;
    int l2=(1<<x)+(1<<(x+1)),r2=(1<<(x+2))-1;
    sort(b+1,b+1+n);
    int j1=1,j2=1;
    LL res=0;
    for(int i=n;i>=1;--i){
        while(j1<=n&&b[i]+b[j1]<l1)++j1;
        while(j2<=n&&b[i]+b[j2]<=r1)++j2;
        res+=j2-1-j1+1;
        if(j1<=i&&i<j2)--res;
    }
    j1=1,j2=1;
    for(int i=n;i>=1;--i){
        while(j1<=n&&b[i]+b[j1]<l2)++j1;
        while(j2<=n&&b[i]+b[j2]<=r2)++j2;
        res+=j2-j1;
        if(j1<=i&&i<j2)--res;
    }
    res>>=1;
    return res&1;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int res=0;
    for(int i=0;i<=24;++i)res|=(check(i)<<i);
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int Tt=1;
    //cin>>Tt;
    while(Tt--){
        solve();
    }
    return 0;
}