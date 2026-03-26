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
void merge(int u, int v) {
    u = get(u); v = get(v);
    if(u==v)return;
    p[u]=v; c[v] += c[u];
}
void doWork() {

    cin >> n >> m;
    map<int, vector<int>> mp;
    string s;
    cin >> s;
    f(i,1,m+1) {
        int sz;
        cin >> sz;
        f(j,0,sz) {
            int x;
            cin >> x;
            mp[x-1].pb(i);
        }
    }

    f(i,1,2*m+1) {
        p[i]=i;
        c[i] = (i > m);
    }
    c[0] = 1e9;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        auto & vec= mp[i];
            if(vec.size() == 1) {
                int node = vec[0];
                ans -= calc(node);
                merge(node+(s[i]=='1')*m,0);
                ans += calc(node);
            }   else if(vec.size() == 2) {
                int u = vec[0], v = vec[1];
                if(s[i] == '0' && get(u) != get(v+m)) {
                    ans -= calc(u); ans -= calc(v);
                    merge(u,v+m);   merge(u+m,v);
                    ans += calc(u);
                }
                if(s[i] == '1' && get(u) != get(v)) {
                    ans -= calc(u); ans -= calc(v);
                    merge(u,v); merge(u+m,v+m);
                    ans += calc(u);
                }
            }
            cout << ans << '\n';
    }


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
