//Author: Ankush Bhagat (https://github.com/ankushbhagat124)
//RFIPITIDS
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N = (int)(3e5 + 1);
const int mod = (int)(1e9 + 7);

template <class type1>
using ordered_multiset = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void init()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/**********************************************************************************************************************/

vector <vector <int>> adj;
vector <int> p, c;
vector <int> cnt, ans;
ordered_multiset <int> st;
bool flag = true;

void dfs(int u, int p = -1)
{
    cnt[u] = 1;
    for (auto v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}

void dfs2(int u, int p = -1)
{
    if (c[u] >= cnt[u])
    {
        flag = false;
        return;
    }
    int val = *(st.find_by_order(c[u]));
    ans[u] = val;
    st.erase(st.find(val));
    for (auto v : adj[u])
    {
        if (v != p)
            dfs2(v, u);
    }
}

signed main()
{
    init();
    startTime = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    */

    int t = 1;
    // cin >> t;
    while (t-- && getCurrentTime() <= 5)
    {
        int n;
        cin >> n;
        p = vector <int> (n);
        c = vector <int> (n);
        cnt = vector <int> (n, 0);
        ans = vector <int> (n, 0);

        adj = vector <vector <int>> (n);
        int root = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> c[i];
            p[i]--;
            if (p[i] >= 0)
            {
                adj[i].push_back(p[i]);
                adj[p[i]].push_back(i);
            }
            else
                root = i;
        }

        dfs(root);
        debug(cnt);

        for (int i = 1; i <= 2 * n; i++)
            st.insert(i);

        flag = true;
        dfs2(root);

        if (!flag)
            cout << "NO";
        else
        {
            cout << "YES" << endl;
            for (auto x : ans)
                cout << x << " ";
        }
    }

    double time = getCurrentTime();
    debug(time);
}