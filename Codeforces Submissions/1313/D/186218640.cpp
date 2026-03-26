#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;

const int NMAX = 100001;
const int VMAX = 41;
const int INF = 1e9;
const int MOD = 1000000009;
const int BLOCK = 318;
const int base = 31;
const int nrbits = 21;

int dp[2][(1 << 8)];
int best[2][(1 << 8)];
vector <int> intervals[NMAX * 2];
pii v[NMAX];
int valoare[NMAX * 2];
pii capete[NMAX * 2];
int cnt = 0;
vector <pii> nrm;

void maxSelf(int &x, int val){
    x = max(x, val);
}

int main() {
#ifdef HOME
    ifstream cin(".in");
    ofstream cout(".out");
#endif // HOME
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, i;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++){
        cin >> v[i].first >> v[i].second;
        nrm.push_back({v[i].first, 0});
        nrm.push_back({v[i].second, 1});
    }
    sort(nrm.begin(), nrm.end());
    for(int i = 1; i < nrm.size(); i++){
        if(nrm[i] != nrm[i - 1]){
            cnt++;
            capete[cnt] = {nrm[i - 1].first + (nrm[i - 1].second == 1), nrm[i].first - (nrm[i].second == 0)};
            valoare[cnt] = capete[cnt].second - capete[cnt].first + 1;
            if(valoare[cnt] <= 0)
                cnt--;
        }
    }
    for(i = 1; i <= n; i++){
        int r = 0, pas = (1 << nrbits);
        while(pas){
            if(r + pas <= cnt && capete[r + pas].first < v[i].first)
                r += pas;
            pas /= 2;
        }
        r++;
        while(r <= cnt && capete[r].second <= v[i].second){
            intervals[r].push_back(i);
            r++;
        }
    }
    int maxim = 0;
    for(i = 1; i <= cnt; i++){
        int acum = i%2;
        int last = 1 - acum;
        int cate = intervals[i].size();
        if(cate == 0){
            dp[acum][0] = maxim;
            continue;
        }
        for(int j = 0; j < (1 << cate); j++){
            dp[acum][j] = -INF;
            best[acum][j] = -INF;
        }
        vector <int> corespunde(cate, -1), comun(intervals[i - 1].size(), -1);
        if(i > 1){
            for(int j = 0; j < intervals[i].size(); j++){
                for(int k = 0; k < intervals[i - 1].size(); k++){
                    if(intervals[i][j] == intervals[i - 1][k]){
                        corespunde[j] = k;
                        comun[k] = j;
                    }
                }
            }
        }
        for(int j = (1 << intervals[i - 1].size()) - 1; j >= 0; j--){
            for(int bit = 0; bit < intervals[i - 1].size(); bit++){
                if((j & (1 << bit)) || (comun[bit] != -1)) continue;
                maxSelf(dp[last][j], dp[last][j | (1 << bit)]);
            }
        }
        for(int j = 0; j < (1 << intervals[i - 1].size()) - 1; j++){
            for(int bit = 0; bit < intervals[i - 1].size(); bit++){
                if(!(j & (1 << bit)) || (comun[bit] != -1)) continue;
                maxSelf(dp[last][j], dp[last][j ^ (1 << bit)]);
            }
        }
        for(int j = 0; j < (1 << cate); j++){
            int oblig = 0;
            for(int bit = 0; bit < cate; bit++){
                if((j & (1 << bit)) && corespunde[bit] != -1){
                    oblig |= (1 << corespunde[bit]);
                }
            }
            dp[acum][j] = ((__builtin_popcount(j)) % 2 == 1) * valoare[i] + dp[last][oblig];
            maxSelf(maxim, dp[acum][j]);
        }
    }
    cout << maxim;
    return 0;
}
