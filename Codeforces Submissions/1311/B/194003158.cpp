#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define sp ' '
#define pb push_back
#define assert(x,a) if(x){cout << a << endl;return;}
#define sortv(x)sort(x.begin(),x.end())
#define revev(x)reverse(x.begin(),x.end())
const ll mod = 1000000007;
vector<vector<int>>graph;
map<int,int>mapping;
int id = 1;
inline void fast(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}
using namespace std;
ll gcd(ll a,ll b)
{
 if ( b == 0 ) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return (a * b) / gcd(a,b);
}
void debug(vector<int>&l)
{
    for(auto &it : l)cout << it << sp;
    cout << endl;
}

void solve()
{
    int a,b;cin >>a >> b;
    vector<int>l(a);for(int &e : l)cin >> e;
    vector<int>pairs(b);for(int &e : pairs)cin >> e;
    sortv(pairs);
    map<int,int>w;
    int last_one = -2;
    for(int i = 0;i < pairs.size();i++)
    {
        if(pairs[i] != a)
        {
            w[l[pairs[i] - 1]]++;
            if(last_one == -2)
            {
                last_one = pairs[i] - 1;
            }
        }
        if(i + 1 != pairs.size() && pairs[i + 1] - 1== pairs[i])
        {
           continue;
        }
       else
        {
            w[l[pairs[i]]]++;
            auto it = w.begin();
            for (int j = last_one; j<= pairs[i]; j++)
            {
                if (it->second != 0)
                    l[j] = it->first;
                it->second--;
                while (it != w.end() && it->second == 0)
                    it++;
            }
            last_one = -2;
            w.clear();
        }
    }
    if(is_sorted(l.begin(),l.end()))
    cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    fast();
    ll t{ 1 };cin >> t;
  // cin.ignore();
    while (t--)
    {
        solve();
    }
}
