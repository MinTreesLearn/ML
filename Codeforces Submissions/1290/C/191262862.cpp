#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
#define pb push_back
#define all(a) a.begin(),a.end()
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;typedef pair<int,int> pii;typedef pair<ll,ll> pll;
template<class T>inline void read(T &x){
    x=0; char ch=getchar(); bool f=0;
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
    if(f) x=-x;
}
template<class T,class... V>
inline void read(T &a,V&... b){read(a); read(b...);}
const int maxn = 600100, maxm = 1000100, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f; const double eps = 1e-8;
template <typename T> inline void chkmax(T &x,const T &y){x=x>y?x:y;}
template <typename T> inline void chkmin(T &x,const T &y){x=x<y?x:y;}

int n, k, c, t;
string s;
vector<int> v[maxn];
int p[maxn], sum[maxn], w[maxn];

int find(int x) { return p[x] == x? x: p[x] = find(p[x]); }
void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if(pu != pv) p[pu] = pv, w[pv] += w[pu]; 
}
int get(int x) {
    return min(w[find(x)], w[find(x + k)]);
}

int main() {
    ios;
    cin >> n >> k >> s;
    s = "?" + s;
    t = 2 * k + 1;
    w[t] = (1 << 29);
    p[t] = t;
    for(int i = 1; i <= k; i++) {
        cin >> c;
        for(int j = 1; j <= c; j++) {
            int x;
            cin >> x;
            v[x].pb(i);
        }
    }
    for(int i = 1; i <= 2 * k; i++) p[i] = i;
    for(int i = 1; i <= k; i++) w[i] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(v[i].size() == 1) {
            ans -= get(v[i][0]);
            if(s[i] == '1') unite(v[i][0], t);
            else unite(v[i][0] + k, t);   
            ans += get(v[i][0]); 
        } else if(v[i].size() == 2) {
            int x = v[i][0], y = v[i][1];
            if(s[i] == '0') {
                if(find(x) != find(y + k) && find(x + k) != find(y)) {
                    ans -= get(x) + get(y);
                    unite(x, y + k);
                    unite(x + k, y);
                    ans += get(x);
                }
            } else {
                if(find(x) != find(y) && find(x + k) != find(y + k)) {
                    ans -= get(x) + get(y);
                    unite(x, y);
                    unite(x + k, y + k);
                    ans += get(x);
                }
            }
        }
        cout << ans << endl;
    }
}