/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
 
 

#include <bits/stdc++.h>
#define bfsof main
using namespace std;

typedef long long ll;
typedef long double ld;
const ll Mod = 998244353;
const ll INF = 1e6+10;
//__builtin_popcount计算二进制中1的个数
void solve()
{
	int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    map<int,bool> p;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) 
        {
            int x;
            cin>>x;
            p[x]=true;
        }
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>0;j--)
        {
            if(a[j]<a[j-1]&&p[j]==false)
            {
                cout<<"NO"<<endl;
                return;
            }
            else 
            if(a[j]<a[j-1]) 
            swap(a[j],a[j-1]);
        }
    }
    cout<<"YES"<<endl;
}
int bfsof()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t --)
    solve();
}
