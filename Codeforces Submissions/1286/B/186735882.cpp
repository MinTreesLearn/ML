#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const  int  n1=1000000007;
#define miv map<int,vector<int>>
#define inf 5e18
#define mlv map<ll,vector<ll>>
#define mip map<int,pair<int,int>>
#define mii map<int,int>
#define mll map<ll,ll>
#define umip unordered_map<int,pair<int,int>>
#define umii unordered_map<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define pi = 3.1415926535897932384626
#define INF LLONG_MAX
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define input(a,x,n); for(int i=x;i<n;i++){cin>>a[i];}
#define output(b,x,n);  for(int i=x;i<n;i++){cout<<b[i]<<" ";}
#define umill unordered_map <int,ll>
#define  pvi pair<vector<int>,int>
#define  piv pair<int,vector<int>>

#define in(i,x,n) for(int i=x;i<n;i++)
#define inl(i,x,n) for(ll i=x;i<n;i++)
#define de(i,x,n) for(int i=n;i>=x;i--)
#define del(i,x,n) for(ll i=n;i>=x;i--)
#define trav(it,m) for(auto it=m.begin();it!=m.end();it++)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pll, null_type, less<pll>,
            rb_tree_tag, tree_order_statistics_node_update> ordered_set;
struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() < second.size();
    }
};

vll factorial(ll n)
{
    vll fct(n+1);
    fct[0]=1;
    fct[1]=1;
    inl(i,2,n+1)
    {
        fct[i]=((fct[i-1%n1])*(i%n1))%n1;
    }
    return fct;
}
vll factorial(ll n,ll m)
{
    vll fct(n+1);
    fct[0]=1;
    fct[1]=1;
    inl(i,2,n+1)
    {
        fct[i]=((fct[i-1]%m)*(i%m))%m;
    }
    return fct;
}

 long long power(long long x,ll y)
{
    long long res = 1;
     ll p=n1;
    x = x % p;


    while (y > 0)
    {


        if (y & 1)
            res = ((res%p) * (x%p)) % p;


        y = y >> 1;
        x = ((x%p) * (x%p)) % p;
    }
    return res;
}
long long modInverse(long long n)
{
    return power(n, n1 - 2);
}
vector<bool> SieveOfEratosthenes(ll n){
vector<bool> prime(n + 1, 1); for (ll p = 2; p * p <= n; p++)
if (prime[p] == true) for (ll i = p * p; i <= n; i += p)
prime[i] = false; return prime;}

ll ncr(ll n,ll r,vll &fct)
{

    return 1ll*(((((fct[n]%n1)*(modInverse(fct[r])%n1))%n1)*(modInverse(fct[n-r])%n1))%n1);

}



//   char a[400][400];

 ll cnt(int r1,int r2,int c1,int c2,vvll &pre)
 {
      ll cnt=0;
      if(r1>0&&c1>0)
      {
          cnt=pre[r2][c2]-pre[r2][c1-1]-pre[r1-1][c2]+pre[r1-1][c1-1];
      }
      else if(r1>0)
      {
          cnt=pre[r2][c2]-pre[r1-1][c2];
      }
      else if(c1>0)
      {
          cnt=pre[r2][c2]-pre[r2][c1-1];
      }
      else
      {
          cnt=pre[r2][c2];
      }
      return cnt;

 }
 //ll dp[500][500];
ll ans1;
void dfs1(vvll &adj,ll node,vll &ans,ll p,vll &sub,vll &w,vll &c)
{
    ans[node]=w[c[node]];
    ll curr=0;
    for(auto &u:adj[node])
    {
        if(u==p)continue;
        vll v;
        while(v.size()<sub[u])
        {
            if(curr==c[node])curr++;
            v.pb(w[curr]);
            curr++;
        }
        dfs1(adj,u,ans,node,sub,v,c);
    }





}
void dfs(vvll &adj,ll node,ll p,vll &sub)
{
    sub[node]=1;
    for(auto &u:adj[node])
    {
        if(u!=p)
        {
            dfs(adj,u,node,sub);
            sub[node]+=sub[u];
        }
    }










}
void build(ll l,ll r,vll &a,vll &seg,ll idx)
{
    if(l==r)
    {
        seg[idx]=a[l];
        return;
    }

    ll mid=(l+r)/2;
    build(l,mid,a,seg,2*idx+1);
     build(mid+1,r,a,seg,2*idx+2);
     seg[idx]=__gcd(seg[2*idx+1],seg[2*idx+2]);
     return ;
}
void build1(ll l,ll r,vll &a,vll &seg,ll idx)
{
    if(l==r)
    {
        seg[idx]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build1(l,mid,a,seg,2*idx+1);
     build1(mid+1,r,a,seg,2*idx+2);
     seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
     return ;
}
ll query1(ll l,ll r,ll low,ll high,ll idx,vll &seg)
{
    if(low>=l and high<=r)
    return seg[idx];
    if(low>r or high<l)
        return -1*inf;
    ll mid=(low+high)/2;
    ll x=query1(l,r,low,mid,2*idx+1,seg);
    ll y=query1(l,r,mid+1,high,2*idx+2,seg);
    return max(x,y);


}
ll query(ll l,ll r,ll low,ll high,ll idx,vll &seg)
{
    if(low>=l and high<=r)
    return seg[idx];
    if(low>r or high<l)
        return 0;
    ll mid=(low+high)/2;
    ll x=query(l,r,low,mid,2*idx+1,seg);
    ll y=query(l,r,mid+1,high,2*idx+2,seg);
    return __gcd(x,y);


}
void update(ll l,ll r,vll &seg, ll idx,ll val,ll index,mll &st)
{
    if(l==r)
    {
        ll x=seg[idx];
        if(l==0)
        {
            st[x]--;
            if(st[x]<=0)
                st.erase(x);
            seg[idx]-=val;
            st[seg[idx]]++;



        }
        else
        {
            seg[idx]-=val;

        }
        return;

    }
    ll mid=(l+r)/2;
    if(index>=l and index<=mid)
    {
        update(l,mid,seg,2*idx+1,val,index,st);
    }
    else
    {
        update(mid+1,r,seg,2*idx+2,val,index,st);
    }
    ll x=seg[idx];
    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    if(l==0)
    {
        st[x]--;
        if(st[x]<=0)
            st.erase(x);

        st[seg[idx]]++;


    }
    return;

}
 vll kmp(string str)
 {
     vll v(str.size());
     v[0]=0;
     in(i,1,str.size())
     {
         ll j=v[i-1];
         while(j>0 and str[i]!=str[j])
         {
             j=v[j-1];
         }
         if(str[i]==str[j])
         {
             j++;
         }
         v[i]=j;
     }
     return v;

 }

void fun(vector<int>&A)
{

    int n=A.size();
   int num1=1e9;
   int num2=1e9;
   int c1=0;
   int c2=0;
   for(int i=0;i<n;i++)
   {

       if(A[i]==num1)
       {
           c1++;
       }
       else if(A[i]==num2)
       {
           c2++;
       }
       else if(c1==0)
       {
           num1=A[i];
           c1++;
       }
       else if(c2==0)
       {
           num2=A[i];
           c2++;
       }
       else
       {
           c1--;
           c2--;
       }
   }
   c1=0;
   c2=0;
   for(int i=0;i<n;i++)
   {
       if(A[i]==num1)
       {
           c1++;
       }
       if(A[i]==num2)
       {
           c2++;
       }
   }
   cout<<num1<<" "<<num2<<endl;
   if(c1>(n/3))
   {
       cout<<num1;
   }
  else if(c2>(n/3))
   {
       cout<<num2;
   }
   else
   {

       cout<<-1;
   }
   cout<<endl;
}






/*ll spf[10000001];
void sieve()
{
    spf[1]=1;
    in(i,2,1e7+1)
    {
        spf[i]=i;
    }
    for(int i=4;i<=1e7+1;i+=2)
    {
        spf[i]=2;
    }
    for(int i=3;i*i<=1e7+1;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<=1e7+1;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
}
*/
ll lca(vvll &dp,ll n1,ll n2,vll &dep)
{
    if(dep[n1]<dep[n2])
        swap(n1,n2);
    de(i,0,20)
    {
        if(dep[n1]-(1ll<<i)>=dep[n2])
        {
            n1=dp[n1][i];
        }
    }
    if(n1==n2)
        return n1;
    de(i,0,20)
    {
        if(dp[n1][i]!=dp[n2][i])
        {
            n1=dp[n1][i];
            n2=dp[n2][i];
        }
    }
    return dp[n1][0];

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
ll tt=1;
//cin>>tt;
 //vvll fcmp(200003);
 /*vector<bool>v=SieveOfEratosthenes(3162);
 vll primes;
 in(i,2,3163)
 {
     if(i<v.size())
     {
         if(v[i])
            primes.pb(i);
     }

 }
 //cout<<primes.size()<<"LK"<<endl;
//output(primes,0,primes.size());
//cout<<endl;
//mlv fc;
*/
while(tt--)
//in(x,1,tt+1)
{
   ll n;
   cin>>n;
   vvll adj(n+1);
   vll c(n+1);
   ll root=-1;
   in(i,1,n+1)
   {
       ll p,x;
       cin>>p>>x;
       c[i]=x;
       if(p==0){
        root=i;
        continue;
       }
       adj[p].pb(i);
       adj[i].pb(p);
   }
   vll sub(n+1);
   dfs(adj,root,0,sub);
   vll w;
   int f1=1;
   in(i,1,n+1)
   {
       if(c[i]>sub[i]-1)
       {
           f1=0;
           break;
       }
       w.pb(i);
   }
   if(!f1)
   {
       no;
       continue;
   }
   vll ans(n+1);
   yes;
   dfs1(adj,root,ans,0,sub,w,c);
   output(ans,1,n+1);
   cout<<endl;




}
return 0;
}
