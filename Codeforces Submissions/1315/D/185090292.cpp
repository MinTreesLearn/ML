#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

const int maxn = 2e5 + 7;

struct node {
    LL val;
    LL time;
}a[maxn];

bool cmp(node aa,node bb) {
    if(aa.time == bb.time) {
        return aa.val < bb.val;
    } else {
        return aa.time > bb.time;
    }
}

map<LL,LL>mp;

LL Find(int x) {
    if(mp[x] == 0) return x;
    else return mp[x] = Find(mp[x]);
}

void Merge(LL x,LL y) {
    LL t1 = Find(x);
    LL t2 = Find(y);
    if(t1 != t2) {
        mp[t1] = t2;
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        mp.clear();
        for(int i = 1 ; i <= n ; i++) {
            scanf("%lld",&a[i].val);
        }
        for(int i = 1 ; i <= n ; i++) {
            scanf("%lld",&a[i].time);
        }
        sort(a+1,a+n+1,cmp);
//        for(int i = 1 ; i <= n ; i++) {
//            cout << "i = " << i << " " << a[i].val << " " << a[i].time << endl;
//        }
        LL ans = 0;
        for(int i = 1 ; i <= n ; i++) {
            LL res = Find(a[i].val);
//            cout << "res = " << res << endl;
            Merge(res,res+1);
            ans += a[i].time * (res - a[i].val);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

