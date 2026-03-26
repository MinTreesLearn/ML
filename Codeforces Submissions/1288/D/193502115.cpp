#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include<unordered_set>


#define debug(x) cout<<#x<<" = "<<x<<endl; 
#define fix(prec) cout << setprecision(prec) << fixed;
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define google(t) cout<<"Case #"<<t<<": "; 
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;


//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>  ordered_set;


constexpr ll MAXX = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll P = 1000000007;//998244853;




ll  mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll  mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll  mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m;}


template <typename T> ostream& operator <<(ostream& output, const vector<T>& data)
{
      for (const T& x : data)
            output << x <<" ";
      return output;
}


template <typename T> istream& operator>>(istream& input,vector<T>& data)
{
      for (auto& item : data)
      {
           input >> item;
      }
      return input;
}


/************************************* SIEVE OF ERASTOSTHENES ***************************************************************/


vector<bool> seive(ll n)
{
      vector<bool>arr(n+1, true);
      for( int i=2; i*i <= n ; i++ )
      {
            if(arr[i])
            {
                 for(int j=i*i; j<=n; j+=i)
                 {
                      arr[j] = false;
                 }
            }
      }
      return arr;
}


vector<ll> lp;
vector<ll> prime;
void seive_op( ll n )
{
      lp.assign(n+1,0);
      ll m=0;
      for(int i=2;i<=n;i++)
      {
           if(lp[i] == 0)
           {
               lp[i]=i;
               prime.push_back(i);
               m++;
           }
           for(int j=0 ; (j<m) && (prime[j]<=lp[i]) && (i*prime[j]<=n) ; j++)
           {
                lp[i*prime[j]] = prime[j];
           }
      }
}


/***********************************************************************************************************************************/
map<ll,ll> primefactorisation(ll n)
{
       map<ll,ll>mp;
       while(n!=1)
       {
             mp[lp[n]]++;
             n/=(lp[n]);
       }
       return mp;


}


//Modular Exponetiation (2^k ary method) 
ll mod_exp(ll x, ll y, ll p)
{
      ll ans=1LL,r=1LL;
      x%=p;
      while(r>0&&r<=y)
      {
           if(r&y)
           {
                ans*=x;
                ans%=p;
           }
           r = (r<<1LL);
           x*=x;
           x%=p;
      }
      return ans;
}
ll  mod_inv(ll n, ll p)
{
      /* This works because n and p are coprime as p is already prime in most questions
         and n<p for most question (ie n is not a multiple of p) */
       return mod_exp(n, p - 2LL, p);
}


ll mod_gp(ll a, ll n, ll p)
{
     // this is for computing 1+(a^2)+(a^3)+(a^4)+...(a^n) 
     // total number of terms is n+1
     if(n==0) return 1;
        if(n==1) return (1+a);
        ll ans=(1+a);
     ll temp=1LL;
     if(n%2==1)
     {
              temp=mod_gp(mod_mul(a,a,P),(n-1)/2,P);
                return mod_mul(ans,temp,P);
     }
     else
     {
          temp=mod_gp(mod_mul(a,a,P),(n/2)-1,P);
              ans=mod_mul(ans,temp,P);
              ans=mod_mul(ans,a,P);
              ans=mod_add(ans,1LL,P);
     }
     return ans;
}


bool isprime(ll x)
{
        for (ll i=2; i*i<=x; i++)
        {
              if ( x%i==0 )
              {
                    return 0;
              }
        }
        return 1;
}


bool cmp(pair<ll,ll> p1, pair<ll,ll> p2)
{
        return (p1.first > p2.first);
}


/***************************************** NCR MOD P ****************************************************************************/


vector<ll> fact;
vector<ll> mod_in;
void pre_fermat()
{
       fact.assign( 1000001, 1);
       mod_in.assign( 1000001,1);
       fact[0]=1;
       for(int i=1; i<= (1000000); i++)
       {
             fact[i] = mod_mul(fact[i-1], i, P);
             mod_in[i]=mod_inv(fact[i],P);
       }
}
ll ncr(ll n, ll r, ll p)
{
        if (n < r)
        {
            return 0LL;
        }


        if (r == 0) 
        {
                return 1LL; 
        }


       ll ans=mod_mul(fact[n],mod_mul(mod_in[r],mod_in[n-r],P),P);
       return ans;
}


/************************************************************************************************************************************/


vector<ll> bfs(vector<vector<ll>>&edge, ll start, ll n)
{
      ll curr = start;
      vector<bool> visited(n+1,0);
      vector<ll> lvl(n+1);
      lvl[curr]=0;
      queue<ll> qq;
      qq.push(curr);
      visited[curr]=1;


        while(!qq.empty()) 
        {
               curr=qq.front(); 
               for( ll x : edge[curr] ) 
            {
                  if(!visited[x]) 
                  {
                        lvl[x] = 1 + lvl[curr];
                        qq.push(x);
                        visited[x] = 1;
                  }
            }
            qq.pop();
      }
      return lvl;
}


void dfs(vector<vector<ll>>&edge, ll curr, ll prev)
{
       for(ll x:edge[curr])
       {
            if(x!=prev)
            {
                  dfs(edge,x,curr);
            }
       }
}


vector <string> bor = {"YES","NO"};


void solve()
{
      ll n;
      cin>>n;
      ll m;
      cin>>m;
      vector<vector<ll>>arr(n,vector<ll>(m));
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<m;j++)
            {
                  cin>>arr[i][j];
            }
      }
      ll ans=0;
      vector<ll>brr((1LL<<m)+1,0);
      for(int i=0;i<n;i++)
      {
            for(int j=0;j<(1LL<<m);j++)
            {
                  ll temp=INT_MAX;
                  for(int k=0;k<m;k++)
                  {
                        if(j&(1LL<<k))
                        {
                              temp=min(temp,arr[i][k]);
                        }
                        
                  }
                  brr[j]=max(brr[j],temp);
            }
      } 
      ll curr=0;
      for(int i=0;i<n;i++)
      {
            ll low=0,high=1e9;
            while(low<=high)
            {
                  ll mid=(low+high)/2;
                  ll f=0;
                  for(int j=0;j<m;j++)
                  {
                        if(arr[i][j]<mid)
                        {
                              f|=(1LL<<j);
                        }
                  }
                  if(brr[f]>=mid)
                  {
                        if(mid>ans)
                        {
                              ans=mid;
                              curr=i;
                        }
                        low=mid+1;
                  }
                  else
                  {
                        high=mid-1;
                  }
            }
      }
      // cout<<ans<<"\n";
      for(int j=0;j<n;j++)
      {
            ll v=INT_MAX;
            for(int i=0;i<m;i++)
            {
                  v=min(v,max(arr[curr][i],arr[j][i]));
            }
            if(v==ans)
            {
                  cout<<curr+1<<" "<<j+1<<"\n";
                  return;
            }

      }
       
}






int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     ll t=1;
   
     while (t--)
     {
          solve();
     }


     return 0;
}
