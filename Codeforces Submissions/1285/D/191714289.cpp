#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
int n;
int trie[maxn*30][2], cnt;
void insert(int val)
{
    int x = 0;
    for (int i=(1<<29);i;i>>=1)
    {
        int a = (bool)(val & i);
        if (!trie[x][a]) trie[x][a] = ++cnt;
        x = trie[x][a];
    }
}
int find(int x, int k)
{
    if ((!trie[x][0] && !trie[x][1])) return 0;
    int ans = 0x3f3f3f3f;
    if (trie[x][0]) ans = min(ans, find(trie[x][0], k >> 1));
    if (trie[x][1]) ans = min(ans, find(trie[x][1], k >> 1));
    return trie[x][0] && trie[x][1] ? (k | ans) : ans;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int a;
        scanf("%d",&a);
        insert(a);
    }
    printf("%d\n",find(0, 1<<29));
    return 0;
}