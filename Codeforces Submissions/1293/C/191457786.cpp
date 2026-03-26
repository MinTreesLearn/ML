#include <bits/stdc++.h>
#include <bitset>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define INF 0x3f3f3f3f
#define endl '\n'
#define IO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//#define LOCAL

int bit(int x) {
    return x != 0;
}

int main(){
    IO
    clock_t ccc1 = clock();
#ifdef LOCAL
    ifstream cin("1.in");
    ofstream cout("1.out");
#endif
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2, 0), b(n + 2, 0), c(n + 2, 0);
    int x, y;
    int s = 0;
    while(q --) {
        cin >> x >> y;
        // x == 1
        if(x == 1){
            if(a[y]){
                s -= (bit(b[y - 1]) + bit(b[y]) + bit(b[y + 1]));
                // s -= (bit(b[y - 1]) + bit(b[y]) + bit(b[y + 1]));
            }else {
                s += (bit(b[y - 1]) + bit(b[y]) + bit(b[y + 1]));
                // s += (bit(b[y - 1]) + bit(b[y]) + bit(b[y + 1]));
            }
            a[y] = !a[y];
        }
        else {
            if(b[y]) {
                s -= (bit(a[y - 1]) + bit(a[y]) + bit(a[y + 1]));
                // s -= (bit(a[y - 1]) + bit(a[y]) + bit(a[y + 1]));
            }
            else {
                s += (bit(a[y - 1]) + bit(a[y]) + bit(a[y + 1]));
                // s += (bit(a[y - 1]) + bit(a[y]) + bit(a[y + 1]));
            }
            b[y] = !b[y];
        }
        cout << (s == 0 ? "Yes" : "No") << endl;
    }
end:
    cerr << "Time : " << clock() - ccc1 << "ms" << endl;
    return 0;
}