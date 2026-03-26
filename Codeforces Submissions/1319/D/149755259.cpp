//Now playing: Ariana Grande - Step on Up
//vk - volezh
//tg - kalexina
//cf - splatjov
//супер ламповое место -> dshindov_chat
//ХУЙ ВОЙНЕ!

// #pragma GCC optimize(3)
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC target("avx","sse2")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wc++11-long-long"
#pragma GCC diagnostic ignored "-Wc++11-extensions"

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <fstream>
#include <map>
#include <unordered_set>
 
using ll = long long;
using namespace std;
typedef pair <long long, long long > pii;

void bfs(vector <vector <int> > &inv_graph,  queue <int> &quka, vector < ll > &inv, vector <ll> &ink)
{
    while (quka.size()!=0)
    {
        int v=quka.front();
        quka.pop();
        for (auto el: inv_graph[v])
        {
            if (inv[el]>inv[v]+1)
            {
                inv[el]=inv[v]+1;
                quka.push(el);
                ink[el]=0;
            }
            if (inv[el]==inv[v]+1) ink[el]++;
        }
    }
}

void solve()
{
    int n, m, mn=0, mx=0;
    cin>>n>>m; 
    vector <vector <int> > graph(n);
    vector <vector <int> > inv_graph(n);
    vector <ll > inv(n,1e9);
    vector <ll > ink(n,0);
    queue <int> quka;
    unordered_set <int> t[n];
    for (int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        graph[x].push_back(y);
        inv_graph[y].push_back(x);
    }
    int q;
    cin>>q;
    vector <int> yu(q);
    for (int i=0; i<q; i++)
    {
        cin>>yu[i];
        yu[i]--;
    }
    quka.push(yu[q-1]);
    inv[yu[q-1]]=0;
    ink[yu[q-1]]=1;
    bfs(inv_graph,quka,inv,ink);
    for (int i=0; i<q-1; i++)
    {
        if (inv[yu[i]]!=inv[yu[i+1]]+1)
        {
            mn++;
            mx++;
        }
        else if (ink[yu[i]]!=1) mx++;
    }
    cout<<mn<<" "<<mx<<endl;
}


signed main()
{
    long long t=1;
    // cin>>t;
    while (t) 
    {
        t--;
        solve();
    }
}

