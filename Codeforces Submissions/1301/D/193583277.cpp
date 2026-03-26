#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vdb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef set<int> si;
typedef set<long long> sl;
typedef set<double> sdb;
typedef set<string> ss;
typedef set<char> sc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define ftb(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define ft(i, a, b) for (int i = a, _b = b; i < _b; i++)
#define fgb(i, a, b) for (int i = a, _b = b; i >= _b; i--)
#define fg(i, a, b) for (int i = a, _b = b; i > _b; i--)
#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, string>> ans;
    //xuoi
    int temp = m - 1;
    int z = k / 4;
    int q = temp / 4;
    int mn = min(z, q);
    if (mn > 0) {
        string l = "RRRR";
        ans.push_back({ mn,l });
        temp -= mn * 4;
        k -= mn * 4;
    }
    if (k > 0 && temp > 0) {
        mn = min(k, temp);
        k -= mn;
        string l = "";
        ft(i, 0, mn) {
            l += 'R';
        }
        ans.push_back({ 1,l });
    }
    //nguoc
    temp = m - 1;
    z = k / 4;
    q = temp / 4;
    mn = min(z, q);
    if (mn > 0) {
        string l = "LLLL";
        ans.push_back({ mn,l });
        temp -= mn * 4;
        k -= mn * 4;
    }
    if (k > 0 && temp > 0) {
        mn = min(k, temp);
        k -= mn;
        string l = "";
        ft(i, 0, mn) {
            l += 'L';
        }
        ans.push_back({ 1,l });
    }
    for (int i = 1; i < n;i++) {
        if (k > 0) {
            ans.push_back({ 1,"D" });
            k -= 1;
        }
        temp = m - 1;
        z = k / 4;
        q = temp / 4;
        mn = min(z, q);
        if (mn > 0) {
            string l = "RRRR";
            ans.push_back({ mn,l });
            temp -= mn * 4;
            k -= mn * 4;
        }
        if (k > 0 && temp > 0) {
            mn = min(k, temp);
            k -= mn;
            string l = "";
            ft(i, 0, mn) {
                l += 'R';
            }
            ans.push_back({ 1,l });
        }
        
        temp = m - 1;
        z = k / 3;
        mn = min(temp, z);
        if (mn > 0) {
            string l = "UDL";
            ans.push_back({ mn,l });
            temp -= mn;
            k -= mn * 3;
        }
        if (k > 0 && temp > 0) {
            if (k == 1) {
                ans.push_back({ 1,"U" });
                k -= 1;
            }
            else {
                k -= 2;
                ans.push_back({ 1,"UD" });
            }
        }
    }
    if (k > 0) {
        temp = n - 1;
        z = k / 4;
        q = temp / 4;
        mn = min(z, q);
        if (mn > 0) {
            string l = "UUUU";
            ans.push_back({ mn,l });
            temp -= mn * 4;
            k -= mn * 4;
        }
        if (k > 0 && temp > 0) {
            mn = min(k, temp);
            k -= mn;
            string l = "";
            ft(i, 0, mn) {
                l += 'U';
            }
            ans.push_back({ 1,l });
        }
    }
    if (k > 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto it : ans) {
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}
