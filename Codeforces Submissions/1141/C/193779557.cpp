#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define el "\n"
#define matrix vector<vector<int>>
#define pt complex<ld>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
const ll N = 2e5 + 7, LOG = 20;
const ld pi = acos(-1);
const ll mod = 1e9 + 7;
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
ll n, m, k, x, y;
int a[N];

void dowork() {
    cin >> n;
    set<int> st;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        st.insert(i);
    }
    st.insert(n);
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += a[i];
        while (st.size() && sum + *st.rbegin() > n) {
            st.erase(prev(st.end()));
        }
        while (st.size() && sum + *st.begin() < 1) {
            st.erase(st.begin());
        }
    }
    if (st.size() == 0) {
        cout << -1 << el;
        return;
    }
    vector<int> ans;
    ans.push_back(*st.begin());
    st.clear();
    st.insert(ans.back());
    for (int i = 1; i < n; i++) {
        st.insert(ans.back() + a[i]);
        ans.push_back(ans.back() + a[i]);
    }
   // cout<<st.size()<<" "<<*st.rbegin()<<" "
    if (st.size() != n || *st.rbegin() > n || *st.begin() < 1) {
        cout << -1 << el;
        return;
    }
    for (auto j: ans) {
        cout << j << " ";
    }
    cout << el;
}

int main() {
    fast
    //freopen("cowland.in", "r", stdin);
    //freopen("cowland.out", "w", stdout);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        dowork();
    }
}