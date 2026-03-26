#include <bits/stdc++.h>

#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;

int head[N], nex[N << 1], to[N << 1], cnt=1;
int dp[N], a[N], n;

//cnt:start from 1,no need to memset (-1)
void add(int x, int y) {
    to[cnt] = y;
    nex[cnt] = head[x];
    head[x] = cnt++;
}

void dfs1(int rt, int fa) {
    if(a[rt] == 0)  dp[rt] = -1;//设置dp数组的初值
    else dp[rt] = 1;
    for(int i = head[rt]; i; i = nex[i]) {
        if(to[i] == fa) continue;
        dfs1(to[i], rt);
        dp[rt] = max(dp[rt], dp[rt] + dp[to[i]]);//两种选择，与其子树连接或者不连接。
    }
}

void dfs2(int rt, int fa) {
    for(int i = head[rt]; i; i = nex[i]) {
        if(to[i] == fa) continue;
        dp[to[i]] = max(dp[to[i]], dp[to[i]] + dp[rt] - max(dp[to[i]], 0));
        //这个的de[rt] - max(dp[to[i]], 0)，表示的意思是：如果这个节点在上一躺的dfs中选择了这个儿子节点那么这个点一定是正数，如果这个点是负数，那么他在上一躺就没有被选择到，所以我们不需要减去这个点的值。
        dfs2(to[i], rt);
    }
}

int main() {
    cin>>n;
    int x,y;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++) {
        cin>>x>>y;
        add(x, y);
        add(y, x);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 1; i <= n; i++)
        printf("%d%c", dp[i], i == n ? '\n' : ' ');
    return 0;
}
