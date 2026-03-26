#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define ii pair<int, int>
#define f first
#define s second
using namespace std;
const int N = 1e6 + 10;
int n, it1, it2, res;
int a[N];
ll p[33];
ii b[N], c[N], d[N];
void tros(int bit) {
    it1 = it2 = 0;
    forin(i,1,n) {
        b[i].f = a[b[i].s] & (p[bit + 1] - 1);
        if(!((b[i].f >> bit) & 1)) c[++it1] = b[i];
        else d[++it2] = b[i];
    }
    forin(i,1,it1) b[i] = c[i];
    forin(i,1,it2) b[i + it1] = d[i];
}
int main () {
    cin.tie(0)->sync_with_stdio(0);
    if(fopen("Task.inp","r")) {
        freopen("Task.inp","r",stdin);
        freopen("WA.out","w",stdout);
    }
    p[0] = 1;
    forin(i,1,32) p[i] = p[i - 1] * 2;
    cin>>n;
    forin(i,1,n) {
        cin>>a[i];
        b[i].s = i;
    }
    forin(bit,0,30) {
        tros(bit);
        int j = n, k = n, o = n, h = n, ans = 0;
        ll fi1 = p[bit], la1 = p[bit + 1] - 1;
        ll fi2 = p[bit] + p[bit + 1], la2 = p[bit + 2] - 1;
        forin(i,1,n) {
            int sx = 2 * b[i].f;
            while(b[i].f + b[k].f >= fi1 && k > 0) k--;
            while(b[i].f + b[j].f > la1 && j > 0) j--;
            while(b[i].f + b[h].f >= fi2 && h > 0) h--;
            while(b[i].f + b[o].f > la2 && o > 0) o--;
            if(fi1 <= sx && sx <= la1) ans--;
            else if(fi2 <= sx && sx <= la2) ans--;
            ans += j - k + o - h;
        }
        ans /= 2;
        if(ans % 2) res += p[bit];
    }
    cout<<res;
}
