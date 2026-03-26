#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(x)         \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define dbg(x) ;
#endif

typedef long long ll;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[2 * n];
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];

    sort(arr, arr + 2*n);
    cout << arr[n] - arr[n - 1] << endl;
}

int main()

{
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("errorf.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}