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

const int N = 2e5+5, A = 12, LG = 18, MOD = (119 << 23) + 1;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const int BLK = 450;
int cnt[26][N];
void doWork() {

    string s;
    cin >> s;
    int n = s.size();
    for(char c = 'a'; c <= 'z'; c++) {
        for(int i = 0; i < n; i++) {
            cnt[c-'a'][i + 1] = cnt[c-'a'][i] + (s[i]==c);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(l==r) {
            cout << "YES\n";
            continue;
        }
        int mask = 0;
        for(char c = 'a'; c <= 'z'; c++)
            if(cnt[c-'a'][r]-cnt[c-'a'][l-1])
                mask |= (1 << (c - 'a'));
        if(popCnt(mask) >= 3 || s[l-1] != s[r-1]) {
            cout << "Yes\n";
        }   else {
            cout << "No\n";
        }
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
