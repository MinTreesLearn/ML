#include<bits/stdc++.h>
#define f first
#define s second
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 6e5 + 5, mod = 1e9 + 7; // !
int  pos[N], a[N], P[N];
vector<pair<int,int>> x;
pair<int,int> p[N];
struct node {
    int c, pr, sf, ans;
} t[4 * N];
node merge(node a, node b) {
    node c;
    c.c = a.c + b.c;
    c.pr = (a.pr + b.pr * P[a.c]) % mod;
    c.sf = (b.sf + a.sf * P[b.c]) % mod;
    c.ans = (a.ans * P[b.c] % mod + b.ans * P[a.c] % mod + a.pr * b.sf % mod) % mod;
    return c;
}
void upd(int u, int id, int l, int r) {
    if(l > id || r < id) return;
    if(l == r) {
        t[u].c ^= 1;
        t[u].pr = t[u].sf = pos[l * t[u].c];
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * u, id, l, mid); upd(2 * u + 1, id, mid + 1, r);
    t[u] = merge(t[2 * u], t[2 * u + 1]);
}
int ID(int a, int b) {
    return (lower_bound(x.begin(), x.end(), make_pair(a, b)) - x.begin() + 1);
}
int pwr(int u, int v) {
    int ans = 1;
    while(v) {
        if(v % 2) ans = ans * u  % mod;
        v /= 2;
        u = u * u % mod;
    }
    return ans;
}
main(){
    int n;
    cin >> n; P[0] = 1;
    for(int i = 1; i <= n; i++) cin >> a[i], P[i] = P[i - 1] * 2 % mod, x.push_back({a[i], i});
    int q; cin >> q;

    for(int i = 1; i <= q; i++) {
        cin >> p[i].f >> p[i].s;
        x.push_back({p[i].s, p[i].f});
//        P[i] = P[i - 1] * 2 % mod;
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for(int i = 0; i < x.size(); i++) pos[i + 1] = x[i].f;
    for(int i = 1; i <= n; i++) {
//        cout << ID(a[i], i) << " _ " << pos[ID(a[i], i)]<< endl;
        upd(1, ID(a[i], i), 1, (int)x.size());
//        cout << t[1].ans << endl;
    }
    int D =  pwr(P[n], mod - 2);
    cout << t[1].ans * D % mod << "\n";
    for(int i = 1; i <= q; i++) {
        upd(1, ID(a[p[i].f], p[i].f), 1, x.size());
        a[p[i].f] = p[i].s;
        upd(1, ID(a[p[i].f], p[i].f), 1, x.size());

        cout << t[1].ans * D % mod << "\n";
    }
 }
