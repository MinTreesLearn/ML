#define print_debug true

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const long long MOD = 1000000007;

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

typedef long long ll;

void fileIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

template <class T>
void debug(const T& n) {
    if (print_debug) cerr << n << "\n\n";
}

template <class T>
void debug(const vector<T>& k) {
    if (print_debug) {
        for (int i = 0; i < (int)k.size(); ++i) {
            cerr << k[i] << " ";
        }
        cerr << "\n\n";
    }
}

template <class T>
void debug(const vector<vector<T>>& k) {
    if (print_debug) {
        for (int i = 0; i < (int)k.size(); ++i) {
            for (int j = 0; j < (int)k[i].size(); ++j) {
                cerr << k[i][j] << " ";
            }
            cerr << "\n";
        }
        cerr << "\n";
    }
}

template <class T>
int bin_upper(const vector<T>& k, const T& value) {
    return distance(k.begin(), upper_bound(k.begin(), k.end(), value));
}

template <class T>
int bin_lower(const vector<T>& k, const T& value) {
    return distance(k.begin(), lower_bound(k.begin(), k.end(), value));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll ans = 0;
    vector<ll> vans(n);
    for (int i = 0; i < n; ++i) {
        vector<ll> a(n);
        // set to max
        ll c = 0;
        a[i] = v[i];
        c += v[i];
        for (int j = i + 1; j < n; ++j) {
            a[j] = min(a[j - 1], v[j]);
            c += a[j];
        }
        for (int j = i - 1; j > -1; --j) {
            a[j] = min(a[j + 1], v[j]);
            c += a[j];
        }
        if (c > ans ) {
            ans = c;
            vans = a;
        }
    }
    for (int i =0 ; i < n; ++i) {
        cout << vans[i] << " ";
    }
    cout << "\n";

}