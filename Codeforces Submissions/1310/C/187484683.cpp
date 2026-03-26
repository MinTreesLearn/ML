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
const int mxN = 1e5+1;
const ll oo = 2e18;
struct smallmap {
    int to[26] = {};
    int& operator[](char c) {
        return to[c-'a'];
    }
};
struct Int {
    ll v=0;
    Int& operator+=(const Int& o) {
        v+=o.v;
        v = min(v,oo);
        return *this;
    }
    void unsafeAdd(const Int& o) {
        v+=o.v;
    }
    void unsafeSub(const Int& o) {
        v-=o.v;
    }

    Int operator+(const Int& o) {
        Int res = *this;
        res+=o;
        return res;
    }
};
int main() {
    int n,m; ll k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<smallmap> tr = {{}};
    string cpar = "$";
    vi par = {-1};
    auto add = [&](string str) {
        int at = 0;
        for(auto c : str) {
            if(!tr[at][c]) {
                tr[at][c]=tr.size();
                cpar.push_back(c);
                par.push_back(at);
                tr.push_back({});
            }
            at = tr[at][c];
        }
    };
    for(int i=0;i<n;++i) {
        add(s.substr(i));
    }
    vi ord;
    auto dfs = [&](auto&& self, int at) -> void {
        if(at!=0) ord.push_back(at);
        for(int to='a';to<='z';++to) {
            if(tr[at][to]) {
                self(self,tr[at][to]);
            }
        }
    };
    dfs(dfs,0);
    auto decode = [&](int at) {
        string t;
        while(at!=0) {
            t.push_back(cpar[at]);
            at=par[at];
        }
        reverse(all(t));
        return t;
    };
    auto ways = [&](int at) {
        // decode string
        auto t = decode(at);
        vi until(n);
        for(int i=0;i<n;++i) {
            int j = i;
            while(j<n and j-i<(int)t.size() and t[j-i]==s[j]) ++j;
            if(j-i==(int)t.size()) {
                --j;
            } else if(j!=n and t[j-i]>s[j]) {
                j=n;
            }
            until[i]=j;
        }
        vector<Int> bad(n+1);
        vector<Int> nbad(n+2);
        bad[0].v=1;
        for(int rep=0;rep<m;++rep) {
            fill(all(nbad),Int{0});
            for(int i=0;i<n;++i) {
                nbad[until[i]+1]+=bad[i];
            }
            partial_sum(all(nbad)-1,bad.begin());
        }
        return bad[n];
    };
    int lo = 0, hi = ord.size()-1;
    while(lo<hi) {
        auto mid = (lo+hi+1)/2;
        if(ways(ord[mid]).v>=k) {
            lo = mid;
        } else hi = mid-1;
    }
    cout << decode(ord[lo]) << '\n';
    
}