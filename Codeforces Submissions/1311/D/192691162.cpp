#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef set<ll> sll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {return a == 0? b: gcd(b%a,a);}
ll lcm(ll a, ll b) {return a * (b / gcd(a,b));}
#define inf 1e17
#define pb(x) push_back(x)
#define rep(x,n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define fo(x) find_by_order(x)
#define ok(x) order_of_key(x)
ll mod = 1e9 + 7;
const int MAXN = 1e5;

void solve(){
    int a,b,c; cin >> a >> b >> c;
    int op = INT_MAX, ra,rb,rc;

    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j+= i) {
            int res = abs(i - a) + abs(j - b) + min(c % j, j - (c % j));
            if (res < op) {
                ra = i; rb = j;
                op = res;
                if (c % j < j - (c % j)) rc = c - (c % j);
                else rc = c + (j - (c % j));
            }
        }
    }
    cout << op << "\n";
    cout << ra << " " << rb << " " << rc << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}