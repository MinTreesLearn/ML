// going to keep 1000th special

// only one doubt -> how the total edges are being calculated

#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

void solve(){
    ll n;cin>>n;
    ll N = (1<<18);
    vector <ll> cnt(N,0);
    vector <bool> done(N,false);
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll t;cin>>t;
        cnt[t]++;
        ans -= t;
    }
    cnt[0]++;
    dsu D(N);
    for(ll mask=N-1;mask>=0;mask--){
        for(ll subMask = mask;subMask > 0;subMask = (subMask - 1) & mask){
            ll u = subMask;
            ll v = (subMask ^ mask);
            if(cnt[u] > 0 && cnt[v] > 0){
                if(D.leader(u) != D.leader(v)){
                    D.merge(u,v);
                    ll mul = cnt[u];
                    if(done[u]){
                        mul = 1;
                    }
                    if(done[v] == false){
                        mul += cnt[v] - 1;
                    }
                    ans += mask * mul;
                    done[u] = true;
                    done[v] = true;
                }
            }
        }
    }
    cout << ans << "\n" ;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}