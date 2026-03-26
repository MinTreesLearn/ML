#include<bits/stdc++.h>
#pragma GCC target ("sse4.2")
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
// #define int long long int
#define ld long double
#define fon(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<int>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define setbits(x) __builtin_popcountll(x)
#define M (1000*1000*1000+7)
#define sz(x) ((int)(x).size())
#define endl "\n"
#define test int T; cin>>T; while(T--)
#define all(z) z.begin() , z.end()
#define allr(z) z.rbegin() , z.rend()
#define sp(x,y)   fixed << setprecision(x) << y
#define memo(oo , zz) memset(oo , zz , sizeof(oo))
//template<typename T>
//using ordered_set = tree<T , null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// DEBUG START=======================================================================================
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// DEBUG END =====================================================================================

bool sortbyme(pii a , pii b)
{
    return a.ss > b.ss;
}

const long long inf = 1e18;
const int N = 1e5;

vii minimum_lis_sequence(string s , int n) {
    vii res;
    int i = 0;
    int val = n+1;
    while(i < n) {
        size_t pos = s.find('<' , i);
        if(pos == string::npos) {
            pos = n;
        }
        int j = pos;
        vii v2;
        while(j < n && s[j] == '<') {
            v2.eb(val--);
            j++;
        }
        vii v1;
        while(i < pos && pos != string::npos) {
            v1.eb(val--);
            i++;
        }
        if(res.empty()) {
            v1.eb(val--);
        }
        reverse(all(v2));
        res.insert(res.end() , all(v1));
        res.insert(res.end() , all(v2));
        i = j;
    }
    return res;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    // first let's find the sequence for the smallest length of lis

    vii min_lis = minimum_lis_sequence(s , n-1);
    reverse(all(s));
    for(char &c : s) {
        if(c == '<') {
            c = '>';
        }
        else {
            c = '<';
        }
    }
    vii max_lis = minimum_lis_sequence(s , n-1);

    reverse(all(max_lis));

    for(int i = 0 ; i < n ; i++) {
        cout << min_lis[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < n ; i++) {
        cout << max_lis[i] << " ";
    }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    test
    {
       solve();
    }
}