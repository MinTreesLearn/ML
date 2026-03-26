#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll     long long
#define test   int _TEST; cin>>_TEST; while(_TEST--)
#define ff     first
#define ss     second
#define pb     push_back
#define ppb    pop_back
#define pf     push_front
#define ppf    pop_front

template <typename T> using Ordered_Set_Tree =
        tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using Ordered_Multiset_Tree =
        tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B> ostream& operator<<(ostream& s, const pair<A, B>& self) {s << self.first << ' ' << self.second << ' '; return s; }
template <typename T> ostream& operator<<(ostream& s, const vector<T>& self) { for (auto e : self) { s << e << '\n'; } return s; }
template <typename T> ostream& operator<<(ostream& s, tuple<T, T, T>& self) { s << get<0>(self) << ' ' << get<1>(self) << ' ' << get<2>(self); return s; }
template <typename A, typename B> istream& operator>>(istream& s, pair<A, B>& self) { s >> self.first >> self.second; return s; }
template <typename T> istream& operator>>(istream& s, tuple<T, T, T>& self) { s >> get<0>(self) >> get<1>(self) >> get<2>(self); return s; }
template <typename T> istream& operator>>(istream& s, tuple<T, T, T, T>& self) { s >> get<0>(self) >> get<1>(self) >> get<2>(self) >> get<3>(self); return s; }
template <typename T> istream& operator>>(istream& s, vector<T>& self) { for (size_t i = 0; i < self.size(); ++i) { s >> self[i]; } return s; }

///DEBUG
void _Print(int t) {cerr << t;}
void _Print(string t) {cerr << t;}
void _Print(char t) {cerr << t;}
void _Print(long long t) {cerr << t;}
void _Print(double t) {cerr << t;}
void _Print(unsigned long long t) {cerr << t;}

template <class T, class V> void _Print(pair <T, V> &p);
template <class T> void _Print(list <T> &v);
template <class T> void _Print(vector <T> &v);
template <class T> void _Print(deque <T> &v);
template <class T, class V> void _Print(T *v, V sz);
template <class T, class V, class P> void _Print(T *v, V sz, P sm);
template <class T> void _Print(set <T> &v);
template <class T, class V> void _Print(map <T, V> &v);
template <class T> void _Print(multiset <T> &v);

template <class T, class V> void _Print(pair <T, V> &p) {cerr << "{"; _Print(p.ff); cerr << ","; _Print(p.ss); cerr << "}\n\n";}
template <class T> void _Print(list <T> &v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T> void _Print(vector <T> &v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T> void _Print(deque <T> &v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T, class V> void _Print(T *v, V sz) {cerr << "[ "; for(int i=0; i<sz; i++) {_Print(v[i]); cerr << " ";} cerr << "]\n\n";}
template <class T, class V, class P> void _Print(T *v, V sz, P sm) {cerr << "[\n"; for(int i=0; i<sz; i++) { for(int j=0; j<sm; j++) {_Print(v[i][j]); cerr << " ";} cerr << "\n";} cerr << "]\n\n";}
template <class T> void _Print(set <T> &v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T> void _Print(multiset <T>& v) {cerr << "[ "; for (T i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}
template <class T, class V> void _Print(map <T, V> &v) {cerr << "[ "; for (auto i : v) {_Print(i); cerr << " ";} cerr << "]\n\n";}

#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
vector<string> vec_splitter(string s)
{
    s += ',';
    vector<string> res;
    while(!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
///DEBUG


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    test
    {
        int n, d;
        cin>>n>>d;

        int mmax = (n*(n-1))/2;
        int mmin = 0;

        int x = n-1, dd=1, mul=2;
        while(x > mul)
        {
            mmin += mul * dd;
            dd++;
            x -= mul;
            mul *= 2;
        }

        mmin += x * dd;

        if(d>mmax || d<mmin)
        {
            cout<<"NO\n";
            continue;
        }

        ll int val = mmax;

        vector<int> par(n);
        vector<set<int>> canTake(n);
        vector<int> child(n, 0);

        for(int i=0; i<n; i++)
        {
            canTake[i].insert(i);
            par[i] = i-1;
            child[i] = 1;
        }
        child[n-1] = 0;

        for(int u=n-1; u>0 && val>d; u--)
        {
            int dig = u-1;

            while(dig && val>d && canTake[dig-1].size()>0)
            {
                val--;
                dig--;
            }

            child[par[u]]--;

            par[u] = *canTake[dig].begin();
            child[*canTake[dig].begin()]++;

            if(child[*canTake[dig].begin()] == 2)
                canTake[dig].erase(canTake[dig].begin());

            canTake[dig+1].insert(u);
        }

        cout<<"YES\n";
        for(int i=1; i<n; i++)
            cout<<par[i]+1<<" ";
        cout<<"\n";
    }
}
