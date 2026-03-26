// LUOGU_RID: 97831402
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define FR first
#define SE second
#define int long long
using namespace std;
inline int read() {
    int x = 0; bool op = 0;
    char c = getchar();
    while(!isdigit(c))op |= (c == '-'), c = getchar();
    while(isdigit(c))x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return op ? -x : x;
}
const int N = 2e5 + 10;
const int INF = 1e14;
int n;
int a[N], ans[N], pos[N];
struct Node {
    int c, sum, mn, mn2, mnc;
    int tg, mtg;
}nd[N << 2];
void build(int k, int l, int r) {
    nd[k].c = nd[k].mnc = nd[k].sum = nd[k].tg = nd[k].mtg = 0; 
    nd[k].mn = nd[k].mn2 = INF;
    if(l == r)return ;
    int mid = l + r >> 1;
    build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
    return ;
}
void mark1(int k, int l, int r, int w) {
    nd[k].sum += w * nd[k].c; nd[k].mn += w; nd[k].mn2 += w;
    nd[k].tg += w;
}
void mark2(int k, int l, int r, int w) {
    nd[k].sum += w * nd[k].mnc; nd[k].mn += w;
    nd[k].mtg += w;
    return ;
}
void pushdown(int k, int l, int r) {
    int mid = l + r >> 1, ls = k << 1, rs = k << 1 | 1;
    mark1(k << 1, l, mid, nd[k].tg);
    mark1(k << 1 | 1, mid + 1, r, nd[k].tg);
    if(nd[ls].mn <= nd[rs].mn)mark2(k << 1, l, mid, nd[k].mtg);
    if(nd[ls].mn >= nd[rs].mn)mark2(k << 1 | 1, mid + 1, r, nd[k].mtg);
    nd[k].tg = nd[k].mtg = 0;
    return ;
}
void pushup(int k) {
    int ls = k << 1, rs = k << 1 | 1;
    nd[k].sum = nd[ls].sum + nd[rs].sum;
    nd[k].c = nd[ls].c + nd[rs].c;
    if(nd[ls].mn < nd[rs].mn) {
        nd[k].mn = nd[ls].mn; nd[k].mnc = nd[ls].mnc;
        nd[k].mn2 = min(nd[ls].mn2, nd[rs].mn);
    }
    else if(nd[ls].mn > nd[rs].mn) {
        nd[k].mn = nd[rs].mn; nd[k].mnc = nd[rs].mnc;
        nd[k].mn2 = min(nd[rs].mn2, nd[ls].mn);
    }
    else {
        nd[k].mn = nd[ls].mn; nd[k].mnc = nd[ls].mnc + nd[rs].mnc;
        nd[k].mn2 = min(nd[ls].mn2, nd[rs].mn2);
    }
    return ;
}
void add(int k, int l, int r, int qx, int qy, int w) {
    if(l >= qx && r <= qy)return mark1(k, l, r, w), void();
    pushdown(k, l, r);
    int mid = l + r >> 1;
    if(qx <= mid)add(k << 1, l, mid, qx, qy, w);
    if(qy > mid)add(k << 1 | 1, mid + 1, r, qx, qy, w);
    pushup(k);
    // printf("add:%d %d %d %d %d\n", l, r, qx, qy, nd[k << 1 | 1].sum);
    return ;
}
void chg(int k, int l, int r, int qx, int qy, int w) {
    if(nd[k].mn >= w)return ;
    if(l >= qx && r <= qy && nd[k].mn2 > w) {
        return mark2(k, l, r, w - nd[k].mn), void();
    }
    pushdown(k, l, r);
    int mid = l + r >> 1;
    if(qx <= mid)chg(k << 1, l, mid, qx, qy, w);
    if(qy > mid)chg(k << 1 | 1, mid + 1, r, qx, qy, w);
    pushup(k);
    return ;
}
void upd(int k, int l, int r, int x) {
    if(l == r) {
        nd[k].c = nd[k].mnc = 1; nd[k].mn = 0;
        return ;
    }
    pushdown(k, l, r);
    int mid = l + r >> 1;
    if(x <= mid)upd(k << 1, l, mid, x);
    else upd(k << 1 | 1, mid + 1, r, x);
    pushup(k);
    return ;
}
int qryc(int k, int l, int r, int qx, int qy) {
    if(l >= qx && r <= qy)return nd[k].c;
    pushdown(k, l, r);
    int mid = l + r >> 1, res = 0;
    if(qx <= mid)res += qryc(k << 1, l, mid, qx, qy);
    if(qy > mid)res += qryc(k << 1 | 1, mid + 1, r, qx, qy);
    return res;
}
void calc() {
    for(int i = 1; i <= n; i++)pos[a[i]] = i;
    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        int x = (pos[i] > 1 ? qryc(1, 1, n, 1, pos[i] - 1) : 0) + 1;
        if(pos[i] < n) {
            add(1, 1, n, pos[i] + 1, n, 1);
            chg(1, 1, n, pos[i] + 1, n, x);
        }
        upd(1, 1, n, pos[i]);
        ans[i] += nd[1].sum;
    }
    return ;
}
signed main() { 
    n = read();
    for(int i = 1; i <= n; i++)a[i] = read();
    calc(); 
    reverse(a + 1, a + 1 + n); 
    calc();
    for(int i = 1; i <= n; i++)printf("%lld\n", i * i - ans[i]);
    return 0;
}