
#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
//const  double pi = acos(-1.0);

const  double eps = 1e-10;
#define all(x)(x).begin(), (x).end()
using namespace std;

const int N = 5e3 + 10;
const ll MOD = 1e9 + 7;
int a[N], total[N];
int n, m;
vector <int> color[N];
int pref[N][N], g[N][N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        total[a[i]]++;
        for (int j = 1; j <= n; j++){
            pref[j][i] += pref[j][i - 1];
        }
        pref[a[i]][i]++;
    }
    for (int i = 1; i <= m; i++){
        int f, h;
        cin >> f >> h;
        color[f].pb(h);
    }
    for (int i = 1; i <= n; i++){
        sort(all(color[i]));
        for (int h : color[i]){
            g[i][h]++;
        }
        for (int j = 1; j <= n; j++){
            g[i][j] += g[i][j - 1];
        }
    }
    ll ans1 = 0;
    ll ans2 = 0;
    for (int posL = 0; posL <= n; posL++){
        ll ans = 1;
        int cntAns = 0;
        for (int i = 1; i <= n; i++){
            if (i == a[posL]){
                bool ok = false;
                int cntR = 0;
                for (int h : color[i]) if (h == pref[i][posL]) ok = true;
                else if (h <= total[i] - pref[i][posL]) cntR++;
                if (ok == false) ans = 0;
                else{
                    if (cntR == 0) cntAns++;
                    else cntAns += 2, ans *= cntR;
                }
            }else{
                int l = pref[i][posL];
                int r = total[i] - l;
                if(g[i][l] * g[i][r] - g[i][min(l, r)] > 0){
					cntAns += 2;
					ans *= 1ll * g[i][l] * g[i][r] - g[i][min(l, r)];
				}else if(g[i][l] > 0 || g[i][r] > 0){
					cntAns++;
					ans *= g[i][l] + g[i][r];
				}
            }
            ans %= MOD;
        }
        if (cntAns == ans1){
            ans2 = (ans2 + ans) % MOD;
        }else if (cntAns > ans1){
            ans1 = cntAns;
            ans2 = ans;
        }
    }
    cout << ans1 << " " << ans2 << endl;
}

int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    //freopen("input.txt", "r", stdin);//freopen("output1.txt", "w", stdout);
    //freopen("bonus.in","r",stdin); freopen("bonus.out", "w", stdout);
    int step;
    step = 1;
    //cin >> step;
    for (int i = 1; i <= step; i++){
        solve();
    }
}