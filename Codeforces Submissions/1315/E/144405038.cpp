#include<bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define ll long long
#define ull unsigned ll
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
#define all(v) (v).begin(),(v).end()
const  double pi = acos(-1.0);
const  double eps = 1e-8;
using namespace std;

const int N = 2e5 + 10;
int t[N][4];
int a[N];
int n, k;
void upd(int &x, int y){
    x = max(x, y);
}
void build(int v, int tl, int tr){
    for (int i = 0; i < 4; i++){
        t[v][i] = -1e9;
    }
    if (tl >= tr) return;
    if (tl + 1 == tr){
        t[v][a[tl] << 1 | a[tr]] = min(1, a[tl] + a[tr]);
        t[v][a[tr] << 1 | a[tl]] = min(1, a[tl] + a[tr]);
    }else{
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                int w1 = (i >> 1);
                int l1 = (i & 1);
                int w2 = (j >> 1);
                int l2 = (j & 1);
                upd(t[v][w1 << 1 | w2], (w1 | w2) + (l1 | l2) + (l1 | l2 | w2) + t[v * 2][i] + t[v * 2 + 1][j]);
                upd(t[v][w2 << 1 | w1], (w1 | w2) + (l1 | l2) + (l1 | l2 | w1) + t[v * 2][i] + t[v * 2 + 1][j]);
                upd(t[v][w1 << 1 | l1], (w1 | w2) + (l1 | l2) + (l1 | w2) + t[v * 2][i] + t[v * 2 + 1][j]);
                upd(t[v][w1 << 1 | l2], (w1 | w2) + (l1 | l2) + (l2 | w2) + t[v * 2][i] + t[v * 2 + 1][j]);
                upd(t[v][w2 << 1 | l1], (w1 | w2) + (l1 | l2) + (l1 | w1) + t[v * 2][i] + t[v * 2 + 1][j]);
                upd(t[v][w2 << 1 | l2], (w1 | w2) + (l1 | l2) + (l2 | w1) + t[v * 2][i] + t[v * 2 + 1][j]);
            }
        }
    }
}
void solve() {
    
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }
    build(1, 1, (1 << n));
    int ans = 0;
    for (int i = 0; i < 4; i++){
        ans = max(ans, t[1][i] + (i > 0));
    }
    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    //freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
    //freopen("fygon.in","r",stdin); freopen("fygon.out", "w", stdout);
    int step = 1;
    //cin >> step;
    for (int i = 0; i < step; i++){
        solve();
    }
}