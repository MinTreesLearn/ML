// ░█████╗░░█████╗░██████╗░███████╗███╗░░░███╗██╗███╗░░██╗███████╗███╗░░░███╗
// ██╔══██╗██╔══██╗██╔══██╗██╔════╝████╗░████║██║████╗░██║██╔════╝████╗░████║
// ██║░░╚═╝██║░░██║██║░░██║█████╗░░██╔████╔██║██║██╔██╗██║█████╗░░██╔████╔██║
// ██║░░██╗██║░░██║██║░░██║██╔══╝░░██║╚██╔╝██║██║██║╚████║██╔══╝░░██║╚██╔╝██║
// ╚█████╔╝╚█████╔╝██████╔╝███████╗██║░╚═╝░██║██║██║░╚███║███████╗██║░╚═╝░██║
// ░╚════╝░░╚════╝░╚═════╝░╚══════╝╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚══════╝╚═╝░░░░░╚═╝
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ios ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define int long long
#define pb push_back

typedef vector<int>vi;
typedef queue<int>qu;
typedef vector<vector<int> >vvi;

int mod1 = 998244353 ;
int mod2 = 1000000007 ;

// ***************************************************************
//SOME HELPFUL FUNCTIONS
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// ***************************************************************
//DEBUGGING
#ifndef ONLINE_JUDGE
#define debug(x) cerr <<#x<<" ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr<<a;}

template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// ***************************************************************

void solve(){
  int n;
  cin>>n;
  int mn=1e9;
  int mx=-1e9;
  vector<int>nums(n);
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  for(int i = 0;i<n;i++){
        if(i > 0 && nums[i] == -1 && nums[i - 1] != -1)
            mn = min(mn , nums[i - 1]) , mx = max(mx , nums[i - 1]);
        if(i < n - 1 && nums[i] == - 1 && nums[i + 1] != -1)
            mn = min(mn , nums[i + 1]) , mx = max(mx , nums[i + 1]);
    }
    int res = (mx + mn) / 2;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(nums[i] == -1)
            nums[i] = res;
        if(i)
            ans = max(ans,abs(nums[i] - nums[i - 1]));
    }
    cout<<ans<<" "<<res<<endl;


}
//KEEP IN MIND
/*-->stay calm
-->try to think of approaches,implement whatever seems best
-->try to optimise the code
-->keep code neat*/
signed main(){
#ifndef ONLINE_JUDGE
  freopen("error.txt","w",stderr);
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

#endif
  ios
    int t;
    cin>>t;
    while(t--){
        solve();
    }
  return 0;
}
