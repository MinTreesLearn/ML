//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define pii pair <int, int>
#define F first
#define S second
#define int int64_t

using namespace std;

const int N = 4e6+3e5, M = 1e9+7;

mt19937 gen(chrono::system_clock().now().time_since_epoch().count());

struct str {
    int a, b, c;
};

int t[N];
int z[N];

void push (int v, int vl,int vr) {
    if (vl == vr) {
        z[v] = 0;
    }
    else {
        t[(v<<1)] += z[v];
        t[(v<<1)+1] += z[v];
        z[(v<<1)] += z[v];
        z[(v<<1)+1] += z[v];
        z[v] = 0;
    }
}

void upd (int v,int vl, int vr, int l, int r,int x) {
//    cout << v << ' ' << vl << ' ' << vr << ' ' << l << ' ' << r << endl;
    push(v, vl, vr);
    if (vr < l || vl > r) return;
    if (vl >= l && vr <= r) {
        t[v] += x;
        z[v] += x;
        push(v, vl,vr);
        return;
    }
    push(v, vl, vr);
    upd((v<<1), vl, ((vl+vr)>>1), l, r, x);
    upd((v<<1)+1, ((vl+vr)>>1)+1, vr, l, r, x);
    t[v] = max(t[(v<<1)], t[(v<<1)+1]);
}
 

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    str a[n], b[m];
    str c[k];
    for (int i=0;i<n;++i) {
        cin >> a[i].a >> a[i].c;
    }
    for (int i=0;i<m;++i) {
        cin >> b[i].b >> b[i].c;
    }
    for (int i=0;i<k;++i) {
        cin >> c[i].a >> c[i].b >> c[i].c;
    }
    
    sort(a,a+n,[](str a, str b){return a.a < b.a;});
    sort(b,b+m,[](str a, str b){return a.b < b.b;});
    sort(c,c+k,[](str a, str b){return a.a < b.a;});
    
    int it = 0;
    
    for (int i=0;i<m;++i) {
        upd (1, 0,m-1, i, i, -b[i].c);
    }
    
    int ans = -3000000000;
    for (int i=0;i<n;++i) {
//        cout << i << endl;
        while (it < k && c[it].a < a[i].a) {
//            cout << it << endl;
            int l = 0, r = m-1;
            while (l < r) {
                int mid = ((l+r)>>1);
                if (b[mid].b > c[it].b) {
                    r = mid;
                }
                else {
                    l = mid+1;
                }
            }
//            cout <<  l << ' ' << b[l].b << ' '<< c[it].b << endl;
            if (b[l].b > c[it].b) {
                upd(1, 0, m-1, l, m-1,c[it].c);
            }
            it++;
        }
        
        upd(1, 0, m-1, 0, m-1, 0);
        ans = max(ans, t[1]-a[i].c);
    }
    cout << ans;
    return 0;
}
