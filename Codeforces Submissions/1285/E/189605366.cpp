#include <bits/stdc++.h>
#include "stdio.h"

using namespace std;

#define SZ(s) ((int)s.size())
#define all(x) (x).begin(), (x).end()
#define lla(x) (x).rbegin(), (x).rend()
#define bpc(x) __builtin_popcount(x)
#define bpcll(x) __builtin_popcountll(x)
#define MP make_pair
#define endl '\n'

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 2e6 + 3e2;

int lf[N], rg[N];
int cnt[N];

set<pair<int, int>> seg;

void del_point(int x){
    auto it = seg.lower_bound(MP(x + 1, 0));
    if (it == seg.begin()) return;
    --it;
    int l = it->first, r = it->second;
    if (l > x || r < x) return;

    seg.erase(it);
    if (l < x) seg.insert(MP(l, x - 1));
    if (x < r) seg.insert(MP(x + 1, r));
}

void add_point(int x){
    seg.insert(MP(x, x));

    auto it = seg.lower_bound(MP(x, x));
    if (next(it) != seg.end()){
        if (next(it)->first == x + 1){
            pair<int, int> p = *next(it);
            seg.erase(p);
            seg.erase(it);
            p.first = x;
            seg.insert(p);
        }
    }

    it = seg.lower_bound(MP(x, x));
    if (it != seg.begin()){
        if (prev(it)->second == x - 1){
            pair<int, int> p = *prev(it);
            pair<int, int> q = *it;
            seg.erase(p);
            seg.erase(q);
            seg.insert(MP(p.first, q.second));
        }
    }
}

void solve(){
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i <= n; i++){
        cin >> lf[i] >> rg[i];
        mp[lf[i] - 1];
        mp[lf[i]];
        mp[rg[i]];
        mp[rg[i] + 1];
    }

    int z = 0;
    for (auto &now : mp){
        now.second = ++z;
    }

    int lim = 8 * n + 5;
    fill(cnt, cnt + lim, 0);

    for (int i = 1; i <= n; i++){
        lf[i] = mp[lf[i]] * 2, rg[i] = mp[rg[i]] * 2;
        cnt[lf[i]]++;
        cnt[rg[i] + 1]--;
    }

    for (int i = 1; i < lim; i++) cnt[i] += cnt[i - 1];

    seg.clear();
    for (int i = 0; i < lim;){
        if (cnt[i] == 0){
            i++;
            continue;
        }

        int j = i;
        while (j < lim && cnt[j]) j++;
        seg.insert(MP(i, j - 1));
        i = j;
    }

    vector<int> ones;
    for (int i = 0; i < lim; i++){
        if (cnt[i] == 1) ones.push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        int pos = lower_bound(all(ones), lf[i]) - ones.begin();

        for (int j = pos; j < ones.size(); j++){
            if (ones[j] > rg[i]) break;
            del_point(ones[j]);
        }

        int cur = (int)seg.size();
        ans = max(ans, cur);

        for (int j = pos; j < ones.size(); j++){
            if (ones[j] > rg[i]) break;
            add_point(ones[j]);
        }

    }

    cout << ans << endl;

}

int main(){
    clock_t startTime = clock();
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int test_cases = 1;
    cin >> test_cases;

    for (int test = 1; test <= test_cases; test++){
        solve();
    }

    cerr << "Time: " << int((double) (clock() - startTime) / CLOCKS_PER_SEC * 1000) << " ms" << endl;

    return 0;
}