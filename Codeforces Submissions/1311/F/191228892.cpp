// LUOGU_RID: 100872105
#include <bits/stdc++.h>
using namespace std;
#define max_n 200100
#define int long long
void read(int &p)
{
    p = 0;
    int k = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            k = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        p = p * 10 + c - '0';
        c = getchar();
    }
    p *= k;
    return;
}
void write_(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        write_(x / 10);
    }
    putchar(x % 10 + '0');
}
void writesp(int x)
{
    write_(x);
    putchar(' ');
}
void writeln(int x)
{
    write_(x);
    putchar('\n');
}
int n;
pair<int, int> points[max_n];
int tree1[max_n], tree2[max_n];
int lowbit(int x)
{
    return (-x) & x;
}
void add(int x, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tree1[i] += 1;
        tree2[i] += val;
    }
}
int ask1(int x)
{
    int ans = 0;
    //printf("\n");
    for (int i = x; i > 0; i -= lowbit(i))
    {
        ans += tree1[i];
        //printf("%lld ", ans);
    }
    //printf("\n");
    return ans;
}
int ask2(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        ans += tree2[i];
    }
    return ans;
}
int vs[max_n];
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(points[i].first);
    }
    for (int i = 1; i <= n; i++)
    {
        read(points[i].second);
        vs[i] = points[i].second;
    }
    sort(points + 1, points + n + 1);
    sort(vs + 1, vs + n + 1);
    int tot = unique(vs + 1, vs + n + 1) - vs - 1;
    for (int i = 1; i <= n; i++)
    {
        points[i].second = lower_bound(vs + 1, vs + tot + 1, points[i].second) - vs;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        //printf("%lld %lld %lld %lld\n", points[i].first, points[i].second, ask1(points[i].second), ask2(points[i].second));
        ans += points[i].first * ask1(points[i].second) - ask2(points[i].second);
        add(points[i].second, points[i].first);
    }
    writeln(ans);
    return 0;
}
