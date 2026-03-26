/*------------------------------------------------ 
                        \.   \.      __,-"-.__      ./   ./
       \.   \`.  \`.-'"" _,="=._ ""`-.'/  .'/   ./
        \`.  \_`-''      _,="=._      ``-'_/  .'/
         \ `-',-._   _.  _,="=._  ,_   _.-,`-' /
      \. /`,-',-._"""  \ _,="=._ /  """_.-,`-,'\ ./
       \`-'  /    `-._  "       "  _.-'    \  `-'/
       /)   (         \    ,-.    /         )   (\
    ,-'"     `-.       \  /   \  /       .-'     "`-,
  ,'_._         `-.____/ /  _  \ \____.-'         _._`,
 /,'   `.                \_/ \_/                .'   `,\
/'       )                  _                  (       `\
        /   _,-'"`-.  ,++|T|||T|++.  .-'"`-,_   \
       / ,-'        \/|`|`|`|'|'|'|\/        `-, \
      /,'             | | | | | | |             `,\
     /'               ` | | | | | '               `\
                        ` | | | '
                          ` | '                                
              
-------------------------------------------------------*/



#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define oo 1000000010
#define pb(x) push_back(x)
#define loop for(int i=0;i<n;i++)
#define vi   vector <int>
#define pii  pair <int, int>
#define vpi  vector <pii>
#define vpp  vector <pair<int, pii>>
#define mp   map <int, int>
#define mpp  map <pii, int>
#define yes cout << "YES\n";
#define no cout << "NO\n";
constexpr long long SZ = 1e5 + 7;
constexpr long long inf = 1e18;
constexpr long long mod = 1e9 + 7;
constexpr long long MOD = 998244353;
constexpr long double PI = 3.141592653589793238462;
#define ll long long
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define sz(X) (int)X.size()

// Extras
#define fi first
#define se second
#define endl '\n'

// Modulo Arithmetic
int modadd(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int modsub(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int modmul(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }


// GCD
int gcd(int a, int b) { if (b == 0) { return a; } return gcd(b, a % b); }

// LCM
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

class SgTree{
vector<int> seg;
public:
   SgTree(ll n){
       seg=vector<ll>(4*n);
   } 
void Build(vector<int>&ar,ll idx,ll low,ll high){
    if(low==high){
      seg[idx]=(ar[low]);
      return; 
    }
    
    ll mid=(low+high)>>1;
 
    Build(ar,2*idx+1,low,mid);
    Build(ar,2*idx+2,mid+1,high);
 
    seg[idx]=seg[2*idx+1]+seg[2*idx+2]; 
 
}
ll Query(ll idx,ll l,ll r,ll low,ll high){
     //case 1:  No overlap [l r] [low high]  OR [low high] [l r]
      if(l>r)return 0;
 
      if(r<low or high<l)return 0;
 
    // case 2:  Full overlap [l low high r]
 
     if(l<=low and high<=r)return seg[idx]; 
 
     ll mid=(low+high)>>1;
 
    // case 3: partial overlap
    
    ll left=Query(2*idx+1,l,r,low,mid);
    ll right=Query(2*idx+2,l,r,mid+1,high);
 
    return left+right;  
}
  
};



bool isPrime(int n) 
{
    if(n <= 3) return true;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void print(vector<int>& v) 
{
    for(auto& x: v) {
        cout << x << " ";
    }
    cout << endl;
}
int countInversion(vector<int>& v, int n) {
	
	vector<int> suff(n, 0);
	suff[n-1] = v[n-1] == 0;
	for(int i = n - 2; i >= 0; i--) {
		suff[i] += suff[i+1];
		if(v[i] == 0) suff[i]++;
	}
	
	int ans = 0;
	for(int i = 0; i < n-1; i++)
	{
		if(v[i] == 1) {
			ans += suff[i + 1];
		}
	}
	
	// cout << ans << endl;
	return ans;
}
vector<pair<int,int>>vx;
vector<int>visited(1005);
void dfs(vector<vector<int>>&v,int src,int prev,vector<int>&visited){
    visited[src]=1;
    int ans=1;
    for(auto i:v[src]){
        if(!visited[i]){
            dfs(v,i,src,visited);
        }
        else if(visited[i]==1 && i!=prev){
            vx.push_back({src,i});

        }
    }
    visited[src]=INT_MIN;
}
vector<vector<int>> adj;
void bfs(int start){
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);
    visited[start] = true;
  
    int vis;
    while (!q.empty()) {
        vis = q[0];
  
        q.erase(q.begin());
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

int n,k; 
void solve()
{
    int cnt=0,ans=0,sum=0;
    cin>>n;
    int a[n];

    int mx=-2, mn=inf;
    vector<int>v;

	loop{
       	cin>>a[i];
       }

       for(int i=0;i<n-1;i++){
            if(a[i]>=0 and a[i+1]>=0)ans=max( ans, abs(a[i]-a[i+1] ));
            if(a[i]==-1 and a[i+1]>=0)v.pb(a[i+1]);
            if(a[i+1]==-1 and a[i]>=0)v.pb(a[i]);
        }

        sort(v.begin(),v.end());
        if(v.size()){
            mn=v[0];
            mx=v[v.size()-1];

            k=(mx+mn)/2;
            ans=max( ans, mx-k );

            cout<<ans<<" "<<k<<endl;
        }
        else cout<<ans<<" "<<0<<endl;

}
int32_t main()
{
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}