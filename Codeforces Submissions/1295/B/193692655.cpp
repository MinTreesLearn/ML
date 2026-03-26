//Author: Ankush Bhagat (https://github.com/ankushbhagat124)
//RFIPITIDS?
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int inf = (int)(numeric_limits<int>::max());
const long long N = (long long)(3e5 + 1);
const long long mod = (long long)(1e9 + 7);

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

template<typename T, typename V, typename M>
void __print(const tuple<T, V, M> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(priority_queue<T> &x) {int f = 0; cerr << '{'; while (!x.empty()) { cerr << (f++ ? "," : ""), __print(x.top()); x.pop();} cerr << "}";}
template<typename T>
void __print(stack<T> &x) {int f = 0; cerr << '{'; while (!x.empty()) { cerr << (f++ ? "," : ""), __print(x.top()); x.pop();} cerr << "}";}
template<typename T>
void __print(queue<T> &x) {int f = 0; cerr << '{'; while (!x.empty()) { cerr << (f++ ? "," : ""), __print(x.front()); x.pop();} cerr << "}";}
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


signed main()
{
    init();
    startTime = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*
    10101
    -1 0 -1 0 -1

    */

    int t = 1;
    cin >> t;
    while (t-- && getCurrentTime() <= 5)
    {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;

        vector <long long> v;
        long long curr = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                curr--;
            else
                curr++;
            v.push_back(curr);
        }

        bool flag = false;

        if (curr == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == x)
                    flag = true;
            }
            if (flag)
                cout << "-1";
            else
                cout << 0;
        }
        else
        {
            //x+m*curr = X
            long long ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == x)
                    ans++;
                else
                {
                    long long val = (x - v[i]);
                    if (val * curr > 0 && (abs(val) % abs(curr) == 0))
                        ans++;
                }
            }

            if (x == 0)
                ans++;
            cout << ans;
        }
        cout << endl;
    }

    double time = getCurrentTime();
    debug(time);
}