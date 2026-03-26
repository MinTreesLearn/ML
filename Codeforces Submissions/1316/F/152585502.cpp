#include<bits/stdc++.h>
using namespace std;
#define pb  push_back
#define ll  long long
#define vi  vector<int>
#define vvi vector<vi >
#define all(x) x.begin(), x.end()

ll mod = 1e9 + 7;
vi tw, in;

struct pt {
    ll val, cnt, lva, rva;
    pt() {};
    pt(ll k, ll x) {
        cnt = k;
        val = (x * x % mod) * (k * in[1] % mod + mod - 1 + in[k]) % mod;
        lva = (tw[k] + mod - 1) * x % mod;
        rva = (1 + mod - in[k]) * x % mod;
    }
    pt(ll val, ll cnt, ll lva, ll rva) : val(val), cnt(cnt), lva(lva), rva(rva) {};
};
pt operator+(pt x, pt y) {
    return pt((x.val + y.val + (x.lva * y.rva % mod) * in[x.cnt]) % mod, x.cnt + y.cnt,
              (x.lva + y.lva * tw[x.cnt]) % mod, (x.rva + y.rva * in[x.cnt]) % mod);
}

ll n, m, q;
vi p, x, I, X;
vector<pt> t;

ll po(ll x, ll p) {
    ll res = 1;
    for (; p; p /= 2) {
        if (p % 2)
            res = (res * x) % mod;
        x = (x * x) % mod;
    }
    return res;
}
ll inv(ll x) { return po(x, mod - 2); }

void add(ll i, ll x) {
    ll k = t[i].cnt + 1;
    t[i] = pt(k, x);
    for (i /= 2; i > 0; i /= 2)
        t[i] = (t[i + i] + t[i + i + 1]);
}
void del(ll i, ll x) {
    ll k = t[i].cnt - 1;
    t[i] = pt(k, x);
    for (i /= 2; i > 0; i /= 2)
        t[i] = (t[i + i] + t[i + i + 1]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    ll inv2 = inv(2);
    tw.assign(n + 5, 1);
    in.assign(n + 5, 1);
    for (ll i = 1; i < in.size(); ++i) {
        in[i] = (in[i - 1] * inv2) % mod;
        tw[i] = (tw[i - 1] * 2) % mod;
    }
    p.resize(n);
    for (auto& el : p) {
        cin >> el; x.pb(el);
    }
    cin >> q;
    I = X = vi(q);
    for (ll e = 0; e < q; ++e) {
        cin >> I[e] >> X[e]; --I[e];
        x.pb(X[e]);
    }
    sort(all(x));
    x.resize(unique(all(x)) - x.begin());
    m = 1;
    while (m < x.size())
        m *= 2;
    t.assign(2 * m, pt(0, 0, 0, 0));
    for (auto el : p) {
        ll e = lower_bound(all(x), el) - x.begin();
        add(e + m, el);
    }
    cout << t[1].val << "\n";
    for (ll o = 0; o < q; ++o) {
        ll i = I[o];
        ll to = X[o]; ll eto = lower_bound(all(x), to) - x.begin();
        ll fr = p[i]; ll efr = lower_bound(all(x), fr) - x.begin();
        p[i] = to;
        del(efr + m, fr);
        add(eto + m, to);
        cout << t[1].val << "\n";
    }

    return 0;
}
