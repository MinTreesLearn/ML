#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
using namespace std;


using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;
using uint = unsigned int;
#define pb push_back
#define F first
#define S second
#define f(i, a, b)  for(int i = a; i < b; i++)
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define mp(x,y) make_pair(x,y)
#define popCnt(x) (__builtin_popcountll(x))
#define int ll

const int N = 3e5+5, A = 12, LG = 18, MOD = (119 << 23) + 1;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const int BLK = 450;
int p[N*2], c[N*2];
int n, m;
int get(int i){return p[i]==i?i:p[i]=get(p[i]);}
int calc(int i){return min(c[get(i)],c[get(i+m)]);}
bitset<1024> bt;
void doWork() {

    int n, k;
    cin >> n >> k;
    k = max(k, 2ll);
    k /= 2;
    for(int i = 1; i < n / k; i++)
    for(int j = 0; j < i; j++) {
        for(int l = j * k; l < n; l++) {
            cout << "? " << l + 1 << endl;
            string ret; cin >> ret;
            bt[l] = bt[l] | ret == "Y";
            if(l%k == k-1)
                l += k * (i - 1);
        }
        cout << "R" << endl;
    }

    cout << "! " << n - bt.count() << endl;


}
int32_t main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE
    int t = 1;
//    cin >> t;
    while (t--) {
        doWork();
    }
    return 0;
}
