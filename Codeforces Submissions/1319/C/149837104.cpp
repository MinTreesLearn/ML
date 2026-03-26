#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//#define int long long
using namespace std;
const int X = 1e6 + 1;
struct List {
    int x;
    int prev;
    int next;
};

List mac[X];
int exist[X];
void dlete(int x)
{
    exist[x] = 1;
    int pr = mac[x].prev;
    int nx = mac[x].next;
    mac[pr].next = mac[x].next;
    mac[nx].prev = mac[x].prev;
}

signed main()
{
    int a, b;
    cin >> a ;
    for (int i = 0;i < a;i++)
    {
        char c;
        cin >> c;
        mac[i].next = i + 1;
        mac[i].prev = i - 1;
        mac[i].x = c-'a';
    }
    mac[a].x = -3;
    int ans = 0;
    for (int i = 28;i > 0;i--)
    {
        if (i == 3)
        {
            int k = 0;
        }
        int now = 0;
        while (mac[now].x > i)
        {
            now++;
        }
        while (now != a)
        {
            if (mac[now].x == i)
            {
                if (mac[mac[now].next].x == i - 1)
                {
                    ans++;
                    dlete(now);
                }
                else
                {
                    if (mac[now].prev>=0 && mac[mac[now].prev].x == i - 1)
                    {
                        ans++;
                        dlete(now);
                    }
                }
            }
            now = mac[now].next;
        }
        now = a - 1;
        while (mac[now].x > i)
        {
            now--;
        }
        while (now != -1)
        {
            if (exist[now]== 0 && mac[now].x == i)
            {
                if (mac[mac[now].next].x == i - 1)
                {
                    ans++;
                    dlete(now);
                }
                else
                {
                    if (mac[now].prev >= 0 && mac[mac[now].prev].x == i - 1)
                    {
                        ans++;
                        dlete(now);
                    }
                }
            }
            now = mac[now].prev;
        }
    }
    cout << ans;
}
