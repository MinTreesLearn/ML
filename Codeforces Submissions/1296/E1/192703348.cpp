#include <bits/stdc++.h>
#define fbo find_by_order
#define ook order_of_key
#define del(x) erase(op.find_by_order(op.order_of_key(x)))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#include <string>
using namespace std;
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ps(x) cout << fixed << setprecision(25) << x << endl;
#define el '\n'
typedef long long ll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define eb emplace_back
#define ist insert
//#define sz(c) ll((c).size())
#define mem(x) memset(x,0,sizeof(x))
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define all(x) x.begin(), x.end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T>  istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>  ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}


const ll mod = 1e9+7;
const int N = 2e5+7;
const ll inf = 1e18;


void slv(){
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(s[i]>s[j] && s[j]>s[k]){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    vector<int> res(n);
    res[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(s[i]<s[j]){
                res[i] = 1-res[j];
                break;
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) cout << res[i];
    cout << el;
}


int main() {
    ios;
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    int tc = 1; //cin >> tc;
    while(tc--){
        slv();
    }
    return  0;
}