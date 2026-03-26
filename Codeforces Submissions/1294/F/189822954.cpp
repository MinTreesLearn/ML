#include<iostream>
#include <bits/stdc++.h>
using namespace std;
template<class container> void print(container v) { for (auto& it : v) cout << it << ' ' ;cout <<endl;}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define nd "\n"
#define all(x) (x).begin(), (x).end()
#define popcount(x)  __builtin_popcount(x)
const ll N = 2e5+50 , LOG = 22 , inf = 1e8 , SQ= 550 , mod = 1e9+7;
#define py cout <<"YES"<<endl;
#define pn cout <<"NO"<<endl;
#define pp  cout <<"ppppppppppppppppp"<<nd;
#define lol cout <<"i am here"<<nd;
const  double PI = acos(-1.0);

const int MX = 1000+10;


template <typename T> using min_heap = priority_queue<T , vector <T > , greater <T >  >;

vector< vector <int > > g(N);
ll n;
vector <int > get(){
    auto bfs =[&](int src)->pair<int , vector <int > > {
        vector <int > par(n+5 , -1);
        deque<int > q;
        q.emplace_back(src);
        vector <int > dist(n+5 , inf);
        dist[src] = 0;
        int cur = src;
        while (!q.empty()){
            int sz = (int)q.size();
            while (sz--){
                int node = q.front(); q.pop_front();
                for (auto &ch : g[node]){
                    if (dist[ch] > dist[node]+1){
                        dist[ch] = 1+ dist[node];
                        q.emplace_back(ch);
                        par[ch] = node;
                    }
                }
                cur = node;
            }
        }
        return {cur , par};
    };
    auto p1 = bfs(1);
    auto p2 = bfs(p1.first);
    int node = p2.first;
    vector <int > ans;
    while (node != -1) {
        ans.emplace_back(node);
        node = p2.second[node];
    }
    return ans;
}

void hi(){
   cin >> n;
   for (int i = 1; i < n; ++i){ ll u , v;
       cin  >> u >> v;
       g[u].emplace_back(v);
       g[v].emplace_back(u);
   }
   vector <int >path = get();
   if ((int)path.size() == n){
       cout << n -1<< nd;
       cout << path.front() <<" "<< path[1] <<" "<< path.back() <<nd;
       return;
   }

    //print(path);
   //pp;
   vector <int > mark(n+5);
   for (auto &u : path) mark[u] = 1;
   vector<int > dist(n+5 , inf);
   deque<int > q;
   for (auto &u : path){
       q.emplace_back(u);
       dist[u] = 0;
   }
   int last = -1;
   while (!q.empty()){
        int sz = (int)q.size();
        while (sz--){
            int node = q.front(); q.pop_front();
            for (auto &ch : g[node]){
                if (dist[ch] > dist[node]+1){
                    dist[ch] = 1 + dist[node];
                    q.emplace_back(ch);
                }
            }
            last = node;
        }
   }
    assert(~last);
   cout << (int)path.size()+ dist[last]-1 <<nd;
   cout << path.front() <<" "<< last <<" "<< path.back() <<nd;


}

int main(){
     ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int tt = 1 , tc = 0;
  // cin >> tt;
    while(tt--) hi();
    return 0;
}

