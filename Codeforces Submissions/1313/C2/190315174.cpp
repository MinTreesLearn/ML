// Problem: C2. Skyscrapers (hard version)
// Contest: Codeforces - Codeforces Round #622 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1313/C2
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// User: milan0027

#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define pb push_back
#define int long long
#define lld long double
#define fi first
#define se second
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pair<int,int>>>
#define mii map<int,int>
#define pii pair<int,int>
#define pq priority_queue
#define setbits(a) __builtin_popcountll(a) 
#define ctz(a) __builtin_ctzll(a)
#define clz(a) __builtin_clzll(a)
#define loop(n) for(int i=0;i<n;i++)
#define fo(i,s,e) for(int i=s;i<e;i++)
#define inn(a,n) int n; cin>>n; vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
#define ink(a,n,k) int n,k; cin>>n>>k; vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
#define out(a) for(auto x9: a) cout<<x9<<" "; cout<<"\n";
#define test int _; cin>>_; for(int tt=1;tt<=_;tt++)
#define en "\n"
#define sz(a) (int)a.size()
#define sortf(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.rbegin(),a.rend())
#define all(a) a.begin(),a.end()
#define gsum(a) accumulate(a.begin(),a.end(),0LL)
#define gmax(a) *max_element(a.begin(),a.end())
#define gmin(a) *min_element(a.begin(),a.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int mod = 1000000007;
//const int mod = 998244353;
const int inf = 2100000000;
const lld pi = 3.1415926535897932;
const long long INF = 1e18+5;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// ans val flag temp fin fish eye kill stat tic tac time cnt cost
void yesno(bool xxx)
{
    if(xxx)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
void NGE(vi &arr,vi &ans)
{
    int n=sz(arr);
    stack<int> s;
 
    
    s.push(arr[0]);
 
    // iterate for rest of the elements
    for (int i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
 
        
        while (s.empty() == false && arr[s.top()] > arr[i]) {
            ans[s.top()]=i;
            s.pop();
        }
 
       
        s.push(i);
    }
 
   
    while (s.empty() == false) {
        ans[s.top()]=0;
        s.pop();
    }
}
int32_t main()    
{
 
   fastio;
   //code goes here
   int n;
   cin>>n;
   vi a(n+2,0);
   fo(i,1,n+1)
   cin>>a[i];
   
   vi fans(n+2,0),bans(n+2,0);
   
   NGE(a,fans);
   vi b=a;
   reverse(all(b));
   NGE(b,bans);
   reverse(all(bans));
   
   vi fdp(n+2,0),bdp(n+2,0);
  // out(fans)
   for(int i=n;i>=1;i--)
   {
       fdp[i]=(fans[i]-i)*a[i]+fdp[fans[i]];
       bans[i]=n-bans[i]+1;
   }
   //out(bans)
   for(int i=1;i<=n;i++)
   {
       bdp[i]=(i-bans[i])*a[i]+bdp[bans[i]];
   }
   
   int note=1;
   int ans=0;
   for(int i=1;i<=n;i++)
   {
       int val = bdp[i]+fdp[i+1];
       if(val > ans)
       {
           if(a[i]>a[i+1])
           note=i;
           else
           note=i+1;
           ans=val;
       }
   }
   
   vi fin(n+2,0);
   fin[note]=a[note];
   int r=note;
   while(r<=n)
   {
       int p=r;
       int to=fans[p];
       while(p<to)
       {
           fin[p]=a[r];
           p++;
       }
       r=to;
   }
   int l=note;
   while(l>=1)
   {
       int p=l;
       int to=bans[p];
       while(p>to)
       {
           fin[p]=a[l];
           p--;
       }
       l=to;
   }
   
   for(int i=1;i<=n;i++)
   cout<<fin[i]<<" ";
   
   
  
   
   
   
 
}
 
/*
 
 
 
 
 
 
 
 
 
 
*/
