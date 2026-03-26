// LUOGU_RID: 102244174
#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,p,fac[N],ans;
int main()
{
    scanf("%d%d",&n,&p);
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%p;
    for(int i=1;i<=n;i++)ans=(ans+1ll*fac[i]%p*fac[n-i+1]%p*(n-i+1)%p)%p;
    printf("%d",ans);
}