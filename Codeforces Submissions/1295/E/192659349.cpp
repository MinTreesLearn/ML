#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ld long double
#define int long long
#define uint unsigned long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
const int N = 2e5;
const int INF = 1e18;
const int mod = 1e9 + 7;
const ld EPS = 1e-6;
random_device rn;
mt19937 rnd(rn());
struct SegmentTreeMass
{
    struct Node
    {
        int sum = INF;
        int add = 0;

        Node(int Sum = INF, int Add = 0)
        {
            sum = Sum;
            add = Add;
        }
    };

    Node neutral = Node();
    int n;
    vector<Node> tree;

    SegmentTreeMass(vector<int>& start)
    {
        n = start.size();
        tree.resize(4 * n + 228);
        init(start);
    }

    SegmentTreeMass(int N)
    {
        n = N;
        tree.resize(4 * n + 228);
        vector<int> start(n, 0);
        init(start);
    }

    Node merge(Node n1, Node n2)
    {
        return Node(min(n1.sum, n2.sum));
    }

    void fix(int v, int l, int r)
    {
        tree[v] = merge(tree[v * 2 + 1], tree[v * 2 + 2]);
    }

    void apply(int v, int l, int r, int val)
    {
        tree[v].add += val;
        tree[v].sum += val;
    }

    void init(int v, int l, int r, vector<int>& start)
    {
        if (l + 1 == r)
        {
            tree[v] = Node(start[l], 0);
            return;
        }

        int m = (r + l) / 2;
        init(v * 2 + 1, l, m, start);
        init(v * 2 + 2, m, r, start);
        fix(v, l, r);
    }

    void init(vector<int>& start)
    {
        init(0, 0, n, start);
    }

    void push(int v, int l, int r)
    {
        int m = (r + l) / 2;

        apply(v * 2 + 1, l, m, tree[v].add);
        apply(v * 2 + 2, m, r, tree[v].add);
        tree[v].add = 0;
    }

    // [l: r)
    Node query(int v, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return tree[v];
        }
        if (r <= ql || qr <= l)
        {
            return neutral;
        }

        int m = (r + l) / 2;
        push(v, l, r);
        return merge(
                query(v * 2 + 1, l, m, ql, qr),
                query(v * 2 + 2, m, r, ql, qr));

    }

    Node query(int ql, int qr)
    {
        return query(0, 0, n, ql, qr);
    }

    void add(int v, int l, int r, int ql, int qr, int val)
    {
        if (ql <= l && r <= qr)
        {
            apply(v, l, r, val);
            return;
        }
        if (r <= ql || qr <= l)
        {
            return;
        }

        int m = (r + l) / 2;
        push(v, l, r);
        add(v * 2 + 1, l, m, ql, qr, val);
        add(v * 2 + 2, m, r, ql, qr, val);
        fix(v, l, r);
    }
    void add(int ql, int qr, int val)
    {
        add(0, 0, n, ql, qr, val);
    }
};
int n;
vector<int> t;

// возвращает сумму на префиксе
int sum (int r) {
    int res = 0;
    for (; r > 0; r -= r & -r)
        res += t[r];
    return res;
}

int sum (int l, int r) {
    return sum(r) - sum(l-1);
}

// обновляет нужные t
void add (int k, int x) {
    for (; k <= n; k += k & -k)
        t[k] += x;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    t.assign(n + 1,0);
    vector<int> p(n), a(n);
    vector<int> num(n +1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        num[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> prefs(n + 2);
    for (int i = 1; i <= n; ++i) {
        prefs[i + 1] = prefs[i] + a[num[i]];
    }
    int ans = INF;
    vector<int> ini(n + 1, INF);
    SegmentTreeMass tree(ini);
    int cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        int x = prefs[p[i]] - sum(1, p[i]) + sum(p[i], n);
        cur += a[num[p[i]]];
        tree.add(1, p[i], a[num[p[i]]]);
        tree.add(p[i] + 1, n + 1, -a[num[p[i]]]);
        tree.add(p[i],p[i] + 1, -tree.query(p[i],p[i] + 1).sum + x);
        add(p[i], a[num[p[i]]]);
        if (i + 1 != n) {
            ans = min(ans, cur);
        }
        ans = min(ans,tree.query(1, n + 1).sum);
    }
    cout << ans << endl;
 }