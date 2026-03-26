#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
//#define int long long
using namespace std;
const int X = 1e6 + 1;

vector <int> mac[X];
vector <int> mac1[X];
int used[X];
int Dists[X];
vector <int> way;
signed main()
{
    int a, b;
    cin >> a >> b;
    int s, t;
    //cin >> s >> t;
    for (int i = 0;i < b;i++)
    {
        int from, to;
        cin >> from >> to;
        mac[to].push_back(from);
        mac1[from].push_back(to);
    }
    int siz;
    cin >> siz;
    for (int i = 0;i < siz;i++)
    {
        int g;
        cin >> g;
        way.push_back(g);
    }
    s = way[0];
    t = way[siz - 1];
    siz--;
    queue <int> q;
    used[t] = 1;
    q.push(t);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto y : mac[x])
        {
            if (used[y] == 0)
            {
                used[y] = 1;
                q.push(y);
                Dists[y] = Dists[x] + 1;
            }
        }
    }
    
    int mn = 0;
    int mx = 0;
    way.push_back(t);
    for (int i = 0;i < siz;i++)
    {
        int t = 0, f = 0;
        for (auto x : mac1[way[i]])
        {
            if (Dists[way[i]] == Dists[x] + 1)
            {
                if (x == way[i + 1])
                {
                    t = 1;
                }
                else
                {
                    f = 1;
                }
            }
        }
        if (t == 1 && f == 1)
        {
            mx++;
        }
        if (t == 0)
        {
            mn++;
            mx++;
        }
    }
    cout << mn << " " << mx;
}
