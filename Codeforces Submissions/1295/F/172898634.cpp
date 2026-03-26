#include<bits/stdc++.h>
using namespace std;
const int P=998244353,N=1e3;
using ll=long long;
ll inv[N];
ll POW(ll x,int k=P-2,ll rs=1)
{while(k){if(k&1)rs=rs*x%P;x=x*x%P;k>>=1;}return rs;}
void init()
{
    for(int i=2;i<N;++i)inv[i]=POW(i);
    inv[0]=inv[1]=1;
}
int l[N],r[N],mp[N];
ll dp[N][N],C[N];
int main()
{
    init();
    int n,m=0;scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {scanf("%d%d",&l[i],&r[i]);++r[i];mp[++m]=l[i],mp[++m]=r[i];}
    sort(mp+1,mp+m+1);
    m=unique(mp+1,mp+m+1)-mp-1;
    for(int i=0;i<N;++i)dp[0][i]=1;
    // dp[0][m]=1;
    for(int i=1;i<=n;++i)
    {
        l[i]=lower_bound(mp+1,mp+m+1,l[i])-mp;
        r[i]=lower_bound(mp+1,mp+m+1,r[i])-mp;
    }
    l[0]=1,r[0]=m+1;
    for(int i=1;i<=n;++i)
    {
        for(int j=l[i];j<r[i];++j)
        {
            int len=mp[j+1]-mp[j];
            C[0]=1;
            for(int k=1;k<=i;++k)
            C[k]=C[k-1]*(len+k-1)%P*inv[k]%P;
            for(int k=1;k<=i;++k)
            {
                if(j<l[i-k+1]||j>=r[i-k+1])break;
                dp[i][j]+=dp[i-k][j+1]*C[k]%P;
               
            }
            
        }
        for(int j=m;j;--j)(dp[i][j]+=dp[i][j+1])%=P;//dp[i][0]=1;
    }
    ll rs=dp[n][1];
    //cout<<rs;
    for(int i=1;i<=n;++i)
    rs=rs*POW(mp[r[i]]-mp[l[i]])%P;
    cout<<rs;
}