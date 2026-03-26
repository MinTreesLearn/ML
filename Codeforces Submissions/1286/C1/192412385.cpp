#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
string str;
vector<array<int,3>> es;
string hidden = "xasdungo";
void query(int l, int r) {
    cout << "? " << l+1 << ' ' << r+1 << endl;
    int len = r-l+1;
    vector<int> v(len+1);
    for(int i=0;i<len*(len+1)/2;++i) {
        string s; cin >> s;
        auto& w = v[s.size()];
        for(auto c : s) w+=c;
    }
    // for(int i=l;i<=r;++i) for(int j=i;j<=r;++j) {
    //     string s = hidden.substr(i,j-i+1);
    //     auto& w = v[s.size()];
    //     for(auto c : s) w+=c;
    // }
    // take biggest string, do it times two, subtract out those two?
    vi res = {};
    for(int i=0;i<(len+1)/2;i++) {
        int ans=-v[len-i-1];
        for(int j=0;j<i;++j) {
            ans+=res[j]*(j+1 - (i+2));
        }
        ans += v[len]*(i+2);
        res.push_back(ans);
    }
    for(int i=0;i<len/2;++i) {
        es.push_back({l+i,r-i,res[i]});
    }
    if(len%2==1) {
        str[(l+r)/2]=res.back()/2;
    }
    
}
int main() {
    int n; cin >> n;
    str.resize(n,'?');
    if(n==1) {
        query(0,0);
    } else if(n==2) {
        query(0,0);
        query(0,1);
    } else {
        query(0,(n+1)/2 -1);
        query(0,(n+1)/2 -2);
        query(0,n-1);
    }
    vector<vector<pi>> adj(n);
    for(auto& [u,v,w] : es) adj[u].push_back({v,w}),adj[v].push_back({u,w});
    for(int i=0;i<n;++i) if(str[i]!='?') {
        auto dfs = [&](auto&& self, int at) -> void {
            for(auto [to,w] : adj[at]) if(str[to]=='?') {
                str[to]=w-str[at];
                self(self,to);
            }
        };
        dfs(dfs,i);
        break;
    }
    cout << "! " << str << endl;
    
}