#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct fenwick{
    int N;
    vector<T> sums;
    fenwick(int _N){
        N = _N + 5;
        sums.resize(N, 0);
    }
    T query(int i){
        T res = 0;
        for(; i; i -= i & (-i)) res += sums[i];
        return res;
    }
    void update(int i, T v){
        for(; i < N; i += i & (-i)) sums[i] += v;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n), v(n);
    for(auto& X : x) cin >> X;
    for(auto& V : v) cin >> V;
    vector<int> sorted = x;
    sort(sorted.begin(), sorted.end());
    map<int, int> ind;
    int curr = 1;
    for(int i = 0; i < n; i++){
        if(!ind.count(sorted[i])) ind[sorted[i]] = curr++;
    }
    fenwick<long long> dists(n);
    fenwick<int> pts(n);
    vector<pair<int, int>> points;
    for(int i = 0; i < n; i++) points.emplace_back(x[i], v[i]);
    sort(points.begin(), points.end(), [&](pair<int, int>& a, pair<int, int>& b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int idx = ind[points[i].first];
        ans += 1LL * pts.query(idx) * points[i].first - dists.query(idx);
        pts.update(idx, 1);
        dists.update(idx, points[i].first);
    }
    cout << ans << '\n';
    return 0;   
}