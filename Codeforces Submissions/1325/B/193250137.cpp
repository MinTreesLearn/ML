#include<iostream>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<numeric>
#include<set>
#include<list>
#include<sstream>
#include<functional>
#include<unordered_set>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<iomanip>
#include<ios>
#include<iterator>
#include<unordered_map>
#define print(v) copy(v.begin(), v.end(), ostream_iterator<ll>(cout, " "));
#define neymar ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define el endl
#define ell cout<<endl
#define forn(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define forb(i, n) for (int i = n-1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}
int main() {
    neymar
        ll tc;
    cin >> tc;
    while (tc--) {
        ll n, x; cin >> n;
        set<ll>s;
        forn(i, n) {
            cin >> x;
            s.insert(x);
        }
        cout << s.size() << el;
    }

    return 0;
}