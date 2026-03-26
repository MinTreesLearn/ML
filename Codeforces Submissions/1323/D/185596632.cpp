
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define fasty ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define forinc(x,a,b) for(int x=a;x<=b;x++)
#define fordec(x,a,b) for(int x=a;x>=b;x--)
#define iii pair<ii,int>
#define fi first
#define se second
#define ii pair<int,int>
#define getbit(x,i) ((x>>(i))&1)
#define batbit(x,i) (x|(1ll<<(i)))
#define tatbit(x,i) (x&~(1<<(i)))
#define endl '\n'
#define int long long
#define pb push_back

const int N=4e5+1000;
int a[N] , b[N];
int z[N] , t[N];
int n;
int getkbit(int x,int k)
{
    return x&((1<<(k+1))-1);
}
main()
{
    fasty
   //freopen("task.inp","r",stdin);
   cin>>n;
   forinc(i,1,n)  cin>>a[i];

   int res=0;
   forinc(k,0,25)
   {
       int cnt=0;
       forinc(i,1,n)     z[i]=getkbit(a[i],k);
      // forinc(i,1,n)     t[i]=getkbit(b[i],k);
       sort(z+1,z+n+1);
       vector<int>v;
       //forinc(i,1,n) v.pb(z[i]);
       forinc(i,1,n)
       {
             //2^k<=zi+tj<=2^(k+1)-1;
             //t[j]>=2^k-z[i]
             //2^(k+1)+2^k<=z[i]+t[j]<=2^(k+2)-1;
             int L=lower_bound(v.begin(),v.end(),(1<<k)-z[i])-v.begin();
             int R=upper_bound(v.begin(),v.end(),(1<<(k+1))-1-z[i])-v.begin()-1;
             cnt+=(R-L+1);
             int tmp=(1<<(k+1))+(1<<k);
             int tmp2=(1<<(k+2))-1;
             L=lower_bound(v.begin(),v.end(),tmp-z[i])-v.begin();
             R=upper_bound(v.begin(),v.end(),tmp2-z[i])-v.begin()-1;
             cnt+=(R-L+1);
             v.pb(z[i]);
       }
       if(cnt&1)   res=batbit(res,k);
   }
   cout<<res<<endl;

}

