#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> c;
vector<bool> p;
vector<int> l;
vector<int> pr;
vector<pair<int,int>> oe;
vector<bool> cx;

int64_t ans = 0;

void mrg(int x,int y,bool z)
{
    //cout << x << ' ' << y << ' ' << z << "\n";
    bool cc = 0;
    if((p[x]^p[y]^cx[l[x]]^cx[l[y]]) != z)
    {
        cc = 1;
    }
    x = l[x];
    y = l[y];
    if(x == y)
        return ;
    if(c[x].size() > c[y].size())
        swap(x,y);
   // cout << oe[x].first << ' ' << oe[x].second << ' ' << oe[y].first << ' ' << oe[y].second << "\n";
    ans -= (pr[x] == -1 ? min(oe[x].first,oe[x].second) : (pr[x] == 0  ? oe[x].first : oe[x].second));
    ans -= (pr[y] == -1 ? min(oe[y].first,oe[y].second) : (pr[y] == 0  ? oe[y].first : oe[y].second));
    pair<int,int> toe = oe[y];
    if(cc == 0)
    {
        toe.first += oe[x].first;
        toe.second += oe[x].second;
    }
    else
    {
        toe.second += oe[x].first;
        toe.first += oe[x].second;
    }
    if(pr[x] == -1 && pr[y] == -1)
    {
        pr[y] = -1;
    }
    else if(cc == 1 && (pr[x] == 0 || pr[y] == 1))
    {
        pr[y] = 1;
    }
    else if(cc == 1 && (pr[x] == 1 || pr[y] == 0))
    {
        pr[y] = 0;
    }
    else if(cc == 0 && (pr[x] == 0 || pr[y] == 0))
    {
        pr[y] = 0;
    }
    else
        pr[y] = 1;
    oe[y] = toe;
    //cout << pr[y] << ' ';
   // cout << oe[y].first << ' ' << oe[y].second << "\n";
    ans += (pr[y] == -1 ? min(oe[y].first,oe[y].second) : (pr[y] == 0  ? oe[y].first : oe[y].second));

    for(auto d:c[x])
    {
        c[y].push_back(d);
        l[d] = y;
        p[d] = (p[d]^cx[x]^cx[y]^cc);
    }
    c[x].clear();
    return ;
}
int main()
{
    int n,k;
    cin >> n >> k;
    c.resize(k);
    l.resize(k);
    p.resize(k);
    oe.resize(k);
    pr.resize(k);
    cx.resize(k);
    for(int i = 0;i < k;++i)
    {
        pr[i] = -1;
        cx[i] = 0;
        p[i] = false;
        c[i].push_back(i);
        l[i] = i;
        oe[i] = {1,0};
    }
    string s;
    cin >> s;
    vector<vector<int>> el(n);
    for(int i = 0;i < k;++i)
    {
        int sz;
        cin >> sz;
        for(int j = 0;j < sz;++j)
        {
            int x;
            cin >> x;
            x--;
            el[x].push_back(i);
        }
    }
    for(int i = 0;i < n;++i)
    {
        if(el[i].size() == 1)
        {
            int x = el[i][0];
            int iz = 0;
            if((p[x]^cx[l[x]]) == 0)
                iz= 1;
            x= l[x];
            ans -= (pr[x] == -1 ? min(oe[x].first,oe[x].second) : (pr[x] == 0  ? oe[x].first : oe[x].second));
            pr[x] = (!(s[i]-'0'));
            if(iz)
            {
                swap(oe[x].first,oe[x].second);
                cx[x]=cx[x]^1;
            }
            ans += (pr[x] == -1 ? min(oe[x].first,oe[x].second) : (pr[x] == 0  ? oe[x].first : oe[x].second));
        }
        else if(el[i].size() == 2)
        {
            mrg(el[i][0],el[i][1],!(s[i]-'0'));
        }
        cout << ans << "\n";
    }
    return 0;
}
