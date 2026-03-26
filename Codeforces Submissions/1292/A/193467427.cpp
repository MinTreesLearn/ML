#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
/*CPPCode*/
using namespace std;
#define ll long long
#define mod 1000000007
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define vc vector<char>
#define vs vector<string> 
#define vpi vector<pair<int,int>> 
#define pi pair<int,int> 
#define ff first 
#define ss second 
#define int long long int  
#define endl "\n" 
#define uii unordered_map<int,int> 
#define rep(i,s,l) for(int i=s;i<l;i++)
#define all(x) begin(x), end(x)

void input(vi &v){rep(i,0,v.size())cin>>v[i];}

void output(vi &v){rep(i,0,v.size())cout<<v[i]<<" ";cout<<endl;}

#define maxn 10007
int fact[maxn], ifact[maxn];
int mpow(int a,int b) {
    int res = 1;
    while(b) {
        if(b&1) res *= a, res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
void pre() {
    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    for(int i = 2; i < maxn; i++) fact[i] = fact[i - 1]*i, fact[i] %= mod;
    for(int i = 2; i < maxn; i++) ifact[i] = ifact[i - 1]*mpow(i, mod - 2), ifact[i] %= mod;
}
 int comb(int a,int b) {
    if(b == 0) return 1LL;
    int ans = fact[a];
    ans *= ifact[b];
    ans %= mod;
    ans *= ifact[a - b];
    ans %= mod;
    return ans;
}

int32_t main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int t;
    cin>>t;
    vvi grid(2,vi(n,0));
    int blocked=0;
        while(t--)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            
            int val=(grid[x][y]==0?-1:1);
            grid[x][y]=1-grid[x][y];
            for(int i=-1;i<=1;i++){
                if(y+i<0||y+i>=n){
                    continue;
                }
                else{
                    if(grid[1-x][y+i])
                        blocked+=val;
                }
            }
            if(blocked==0){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    return 0;
}
