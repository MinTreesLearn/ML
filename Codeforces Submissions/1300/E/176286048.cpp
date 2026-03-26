// Problem: E - Water Balance
// Contest: Virtual Judge - SDTBU-ACM集训队20级&&21级---个人赛 3
// URL: https://vjudge.csgrandeur.cn/contest/520962#problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Date: 2022-10-15 19:27:25
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

#define MAXN 1000010

using namespace std;

typedef long long ll;

int n;
ll a[MAXN],sum[MAXN];

double res[MAXN];

struct node{
    int l;
    int r;
    double ave;
}s[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int cnt=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        s[++cnt]={i,i,a[i]};
        
        while(cnt>=2&&s[cnt-1].ave>=s[cnt].ave)
        {
            s[cnt-1].ave=(sum[i]-sum[s[cnt-1].l-1])/(i-s[cnt-1].l+1.);
            s[cnt-1].r=s[cnt].r;
            cnt--;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        //cout << s[i].ave << endl;
        for(int j=s[i].l;j<=s[i].r;j++)
            res[j]=s[i].ave;
    }
    for(int i=1;i<=n;i++)
        printf("%.9f\n",res[i]);
    
    return 0;
}
		 		  		 	 		   		   	   				