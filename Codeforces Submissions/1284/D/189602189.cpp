#include <bits/stdc++.h>
#ifdef ONPC
    #include "t_debug.cpp"
#else
    #define debug(...) 42
#endif
using namespace std;
//namespace pbds = __gnu_pbds;
using ll = long long;
const int inf = 1e9;
const ll infl = 1e18;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(RANDOM);
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) { return is >> p.first >> p.second; }
template<typename Cont> int sz(const Cont& cont) { return int(cont.size()); }
const string fileio = "";
constexpr int tests = 0, nmax = 2e5, nlog = __lg(nmax), mod = 1e9+7;

int nextPower2(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return 1+n;
}

struct SegmentTree {
    // TO CHANGE

    struct Node {
        // defaults
        int sum = 0;
        int value = 0;
        bool marked = false;

        template<typename T>
        void apply(const T& newval, int l, int r) {
            // update
            value = newval;
            sum = (r - l + 1) * value;
            marked = true;
        }
        friend ostream& operator<<(ostream& os, const Node& v) {
            os << "{" << v.sum;
            if (v.marked) os << " !" << v.value;
            return os << "}";
        }
    };

    void push(int v, int l, int r) {
        if (tree[v].marked) {
            int mid = (l + r) / 2;
            int vl = v * 2, vr = v * 2 + 1;
            tree[vl].apply(tree[v].value, l, mid);
            tree[vr].apply(tree[v].value, mid+1, r);
            tree[v].marked = false;
        }
    }

    Node merge(const Node& l, const Node& r) {
        return Node{l.sum + r.sum};
    }

    int n;
    vector<Node> tree;

    // CONSTRUCTION

    SegmentTree(int n) : n(nextPower2(n)) {
        tree.resize(this->n * 2);
        build(1, 0, n-1);
    }

    template<typename T>
    SegmentTree(vector<T> arr) : n(nextPower2(arr.size())) {
        tree.resize(n * 2);
        for (int i = 0; i < arr.size(); i++) {
            // leaves
            int v = n + i;
            tree[v].apply(arr[i], i, i);
        }
        build(1, 0, n-1);
    }

    void build(int v, int l, int r) {
        if (l == r) return;
        int mid = (l + r) / 2;
        int vl = v * 2, vr = v * 2 + 1;
        build(vl, l, mid);
        build(vr, mid+1, r);
        tree[v] = merge(tree[vl], tree[vr]);
    }

    // INTERNALS

    template<typename T>
    void update(int qi, const T& qval, int v, int l, int r) {
        if (l == r) {
            tree[v].apply(qval, l, r);
            return;
        }
        push(v, l, r);
        int mid = (l + r) / 2;
        int vl = v * 2, vr = v * 2 + 1;
        if (qi <= mid) update(qi, qval, vl, l, mid);
        else update(qi, qval, vr, mid+1, r);
        tree[v] = merge(tree[vl], tree[vr]);
    }
    template<typename T>
    void update(int ql, int qr, const T& qval, int v, int l, int r) {
        if (ql <= l && r <= qr) {
            tree[v].apply(qval, l, r);
            return;
        }
        push(v, l, r);
        int mid = (l + r) / 2;
        int vl = v * 2, vr = v * 2 + 1;
        if (ql <= mid) update(ql, qr, qval, vl, l, mid);
        if (mid+1 <= qr) update(ql, qr, qval, vr, mid+1, r);
        tree[v] = merge(tree[vl], tree[vr]);
    }

    Node query(int ql, int qr, int v, int l, int r) {
        if (ql <= l && r <= qr) return tree[v];
        push(v, l, r);
        int mid = (l + r) / 2;
        int vl = v * 2, vr = v * 2 + 1;

        if (qr <= mid) return query(ql, qr, vl, l, mid);
        if (mid+1 <= ql) return query(ql, qr, vr, mid+1, r);
        return merge(query(ql, qr, vl, l, mid), query(ql, qr, vr, mid+1, r));
    }

    // INTERFACE

    template<typename T>
    void update(int i, const T& val) {
        update(i, val, 1, 0, n-1);
    }

    template<typename T>
    void update(int l, int r, const T& val) {
        update(l, r, val, 1, 0, n-1);
    }

    Node query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }
};

int solve() {
    int n; cin >> n;
    if (!cin) return 1;
    vector<pair<int,int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }

    map<int,int> comp;
    for (auto [i, j] : a) comp[i] = comp[j] = 0;
    for (auto [i, j] : b) comp[i] = comp[j] = 0;
    int k = 0;
    for (auto& i : comp) i.second = k++;
    for (auto& [i, j] : a) i = comp[i], j = comp[j];
    for (auto& [i, j] : b) i = comp[i], j = comp[j];
    debug(a);
    debug(b);

    bool res = true;

    for (int rev = 0; rev < 2; rev++) {

        vector<tuple<int,int,int,int>> q;
        q.reserve(2*n);
        for (int i = 0; i < n; i++) {
            q.emplace_back(a[i].first, 1, b[i].first, b[i].second);
            q.emplace_back(a[i].second+1, 0, b[i].first, b[i].second);
        }
        sort(q.begin(), q.end());

        SegmentTree tree(k);
        for (auto [y, t, a, b]: q) {
            if (t == 1) {
                if (tree.query(a, b).sum) res = false;
            } else {
                tree.update(a, b, 1);
            }
        }

        swap(a, b);
    }


    cout << (res ? "YES\n" : "NO\n");

    return 0;
}

signed main() {
    int t = 1;
    #ifdef ONPC
    t = 10000;
    #else
    if (fileio.size()) {freopen((fileio+".in").c_str(),"r",stdin);freopen((fileio+".out").c_str(),"w",stdout);}
    #endif
    cin.tie(0)->sync_with_stdio(0);
    if (tests) cin >> t;
    while (t-- && cin) {
        if (solve()) break;
        #ifdef ONPC
            cout << "____________________" << endl;
        #endif
    }
    return 0;
}

/*
     █████               █████  ███  ████                               
    ▒▒███               ▒▒███  ▒▒▒  ▒▒███                               
  ███████  ████████   ███████  ████  ▒███  █████ ████  ██████  ████████ 
 ███▒▒███ ▒▒███▒▒███ ███▒▒███ ▒▒███  ▒███ ▒▒███ ▒███  ███▒▒███▒▒███▒▒███
▒███ ▒███  ▒███ ▒▒▒ ▒███ ▒███  ▒███  ▒███  ▒███ ▒███ ▒███ ▒███ ▒███ ▒▒▒ 
▒███ ▒███  ▒███     ▒███ ▒███  ▒███  ▒███  ▒███ ▒███ ▒███ ▒███ ▒███     
▒▒████████ █████    ▒▒████████ █████ █████ ▒▒███████ ▒▒██████  █████    
 ▒▒▒▒▒▒▒▒ ▒▒▒▒▒      ▒▒▒▒▒▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒   ▒▒▒▒▒███  ▒▒▒▒▒▒  ▒▒▒▒▒     
                                            ███ ▒███                    
                                           ▒▒██████                     
                                            ▒▒▒▒▒▒
*/