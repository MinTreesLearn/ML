#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define PB push_back
#define pi (double(2) * acos(0.0))
// #define mod (1000000007)
#define eps 1e-3
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

/*
    'A' everywhere ans {0}
     No 'A' ans-> MORTAL
    'A' in corner, ans {1,2}         1 or not, from all A row 
    'P' in all corners ans {2,3,4}   2 when all "A" row or column exists
                                     3 when 'A' in the edge
                                     4 otherwise
*/

ll pow(ll a, ll b) {if (b == 0){return 1;}ll res = pow(a, b / 2);if (b % 2){return res * res * a;}else{return res * res;}}

vi presum(vi a){
    vi pre=a;
    FOR(i,1,a.size()) pre[i]+=pre[i-1];
    return pre;
}
double centre(int x, int y){
    return double((double(x) + double(y))/2.0);
}
bool is_equal(double a, double b){
    return (abs(a-b)<=eps);
}
void solve(){
     int n; cin>>n;
     vvi cord(n, vi(2,0));
     FOR(i,0,n) cin>>cord[i][0]>>cord[i][1];
     if(n&1){
        cout<<"NO";
        return;
     }
     double x = centre(cord[0][0], cord[n/2][0]);
     double y = centre(cord[0][1], cord[n/2][1]);
     FOR(i,1,n){
        if(!is_equal(centre(cord[i][0], cord[(i+n/2)%n][0]),x) || 
           !is_equal(centre(cord[i][1], cord[(i+n/2)%n][1]),y)){
            cout<<"NO";
            return;
        }
     }
     cout<<"YES";     
}


int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    FIO;  
 	int t=1;
 	// cin>>t;
 	int T=1;
    while (t--) {
        // cout<<"Case #"<<T<<": ";
    	solve(); 
    	cout<<endl;       
    	T++;
    }
    return 0;
}


