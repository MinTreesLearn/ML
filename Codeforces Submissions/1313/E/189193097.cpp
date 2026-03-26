#include<bits/stdc++.h>
#define f first
#define s second
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7; // !
int t, fw[2][N], n, h[N], hA[N], hB[N], pwr[N];
vector<int> en[N], st[N];
void upd(int t, int id, int v) {
    for(id; id <= n; id += id & (-id)) fw[t][id] += v;
}
int get(int t, int id) {
    int ans = 0;
    id = min(id, n);
    for(id; id >= 1; id -= id & (-id)) ans += fw[t][id];
    return ans;
}
//int h[N], hA[N], hB[N];
main(){
    int m;
    cin >> n >> m;
    string a, b, s;
    cin >> a >> b >> s;

    a = '#' + a; b = '#' + b; s = '#' + s;
    pwr[0] = 1;
    int p = 37;
    for(int i = 1; i <= m; i++) {
        h[i] = (h[i - 1] * p + s[i] - 'a' + 1) % mod;
        pwr[i] = pwr[i - 1] * p % mod;
    }
    for(int i = 1; i <= n; i++) {
        hA[i] = (hA[i - 1] * p + a[i] - 'a' + 1) % mod;
        hB[i] = (hB[i - 1] * p + b[i] - 'a' + 1) % mod;
    }
    for(int i = 1; i <= n; i++) {
        int l = 1, r = min(m, n - i + 1), x = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if((hA[i + mid - 1] - hA[i - 1] * pwr[mid] % mod + mod) % mod == h[mid]) x = mid, l = mid + 1;
            else r = mid - 1;
        }
        if(x) en[x + 1].push_back(i), upd(0, i, 1);


        l = 1, r = min(i, m), x = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if((hB[i] - hB[i - mid] * pwr[mid] % mod + mod) % mod == (h[m] - h[m - mid] * pwr[mid] % mod + mod) % mod) x = mid, l = mid + 1;
            else r = mid - 1;
        }
        st[min(x, m - 1)].push_back(i);
         // en - st < m - 1; en < st + m - 1
    }

    int cur = 0, ans = 0;
    for(int i = 1; i < m; i++) {
        for(int j = 0; j < en[i].size(); j++) {
            cur -= get(1, en[i][j] + m - 2) - get(1, en[i][j] - 1);
            upd(0, en[i][j], -1);
        }

        for(int j = 0; j < st[m - i].size(); j++) {
            int x = st[m - i][j];

         //   cout << "++++ " << 1 << " " << x << " " << get(0, st[m - i][j]) << endl;
            cur += get(0, st[m - i][j]) - get(0, st[m - i][j] - m + 1);
            upd(1, st[m - i][j], 1);
        }
        ans += cur;
    }
    cout << ans;
 }
