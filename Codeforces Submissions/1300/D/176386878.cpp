#include <bits/stdc++.h>
#define ll unsigned long long
#define sys system("pause");
using namespace std;
vector<pair<double, __int128>> v;
int main()
{
    int n;
    int x;
    pair<int, __int128> p, p1, p2;
    cin >> n;
    cin >> p.first >> x;
    p.second = x;
    p1 = p;
    while (--n)
    {
        cin >> p2.first >> x;
        p2.second = x;
        if (p1.first == p2.first)
        {
            double c = p2.second - p1.second;
            v.push_back({c > 0 ? c : -c, 1e30});
        }
        else
        {
            double f = (p1.second - p2.second) / (p1.first - p2.first);
            __int128 a = (p1.second - p2.second) * (p1.second - p2.second) + (p1.first - p2.first) * (p1.first - p2.first);
            v.push_back({f, a});
        }
        p1 = p2;
    }
    if (p1.first == p.first)
    {
            double c=p.second-p1.second;
            v.push_back({c>0?c:-c, 1e30});
    }
    else
    {
        double f = (p1.second - p.second) / (p1.first - p.first);
        __int128 a = (p1.second - p.second) * (p1.second - p.second) + (p1.first - p.first) * (p1.first - p.first);
        v.push_back({f, a});
    }
    sort(v.begin(), v.end());
    int flag = 0;
    for (int i = 0; i < v.size() / 2; ++i)
        if (v[i * 2] != v[i * 2 + 1])
        {
            flag = 1;
            break;
        }
    puts(flag ? "no" : "yes");
    sys;
    return 0;
}
