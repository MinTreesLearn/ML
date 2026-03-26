// Problem: B - Journey Planning
// Contest: Virtual Judge - SDTBU-ACM集训队20级---个人赛 12
// URL: https://vjudge.csgrandeur.cn/contest/530065#problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date: 2022-11-16 19:22:52
// 
// Powered by CP Editor (https://cpeditor.org)

/**
  * @author  : SDTBU_LY
  * @version : V1.0.0
  * @上联    : ac自动机fail树上dfs序建可持久化线段树
  * @下联    : 后缀自动机的next指针DAG图上求SG函数
**/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

#define MAXN 200010

using namespace std;

typedef long long ll;

int n,b[MAXN];
unordered_map<int,ll> mp;



int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
        mp[b[i]-i]+=b[i];
    }
    ll res=0;
    for(auto i:mp)
        res=max(res,i.second);
    
    cout << res << endl;
    
    return 0;
}
			     	 	  		 	 			    			 	