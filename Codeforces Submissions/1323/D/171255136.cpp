#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <time.h>
#include <stack>
#include <unordered_map>
#include <bitset>
#include <tuple>
#define ll long long
#define MAXN 400010
#define MOD 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mapa make_pair
#define lowbit(x) x&(-x)
#define eps 1e-7
using namespace std;
int a[MAXN],b[MAXN],n;
ll calc(int L,int R)
{
    ll ans=0;
    for(int i=n,l=1,r=1;i>=1;i--)//b[i]减小b[j]增大
    {
        while(l<=n&&b[i]+b[l]<L)l++;//第一次>=L
        while(r<=n&&b[i]+b[r]<=R)r++;//第一次大于R
        ans+=r-l-(l<=i&&i<r);//(i,i)
    }
    return (ans>>1)&1;
}
void slv()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int k=0;k<=24;k++)
    {
        for(int i=1;i<=n;i++)b[i]=a[i]%(1<<(k+1));
        sort(b+1,b+n+1);
        //双指针
        //printf("%d %d",calc(1<<k,(1<<k+1)-1),calc((1<<k)+(1<<k+1),1<<k+2));
        ans|=(calc(1<<k,(1<<k+1)-1)^calc((1<<k)+(1<<k+1),1<<k+2))<<k;
        //printf(" %d\n",ans);
    }
    printf("%d",ans);
}
int main() {
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int _ = 1;//scanf("%d", &_);//cin >> _;
    while(_--)
    {     
        slv();
        printf("\n");// fflush(stdout);
    }
    return 0;

}
//由于卡空间所以拆成两部分