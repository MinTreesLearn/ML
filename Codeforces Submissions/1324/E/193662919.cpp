#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll eps = 1e-9;
typedef vector<int>vi;
typedef vector<ll>vl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define read(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define aff(v) for(int i : v) cout << i << ' ';

int n , h , l , r;
vi v;

int helper(int i, vector<vi>& dp , int hours){
    if(i == n) {
        if(hours <= r && hours >= l) return 1;
        return 0;
    }
    if(dp[i][hours] != -1) return dp[i][hours];
    dp[i][hours] = 0;
    dp[i][hours] = max(dp[i][hours] ,helper(i + 1 , dp , (hours + v[i]) % h));
    dp[i][hours] = max(dp[i][hours] ,helper(i + 1 , dp , (hours + v[i] - 1)%h));
    if(hours <= r && hours >=l && i > 0) dp[i][hours]++;   
    return dp[i][hours];
}

void solve(){
    cin >> n >> h >> l >> r;
    v.resize(n);
    read(v,n);
    vector<vi> dp(max(n ,h) ,vector<int>(max(n,h) , -1));
    cout << helper(0 , dp , 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    //cin >> tc;
    while(tc--)solve();
    return 0;
}
