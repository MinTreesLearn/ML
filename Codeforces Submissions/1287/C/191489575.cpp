#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define PI atan(1.0)*4
#define E 2.718281828
#define rp(i,s,t) for (register int i = (s); i <= (t); i++)
#define RP(i,t,s) for (register int i = (t); i >= (s); i--)
#define ll long long
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define debug printf("ac\n");
using namespace std;
inline int read()
{
    int a=0,b=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            b=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=getchar();
    }
    return a*b;
}
const int INF = 0x3f3f3f3f;
int p[105],visited[105];
vector<int> s1;
vector<int> s2;
int dp[105][105][105][2];
int n;
int dfs(int i,int odd_num,int even_num,int k){
    if(i==n+1) return 0;
    if(dp[i][odd_num][even_num][k]!=-1) return dp[i][odd_num][even_num][k];
    dp[i][odd_num][even_num][k]=0;
    if(p[i]!=0){
        if(k==2||p[i]%2==k) dp[i][odd_num][even_num][k]=dfs(i+1,odd_num,even_num,p[i]%2);
        else dp[i][odd_num][even_num][k]=dfs(i+1,odd_num,even_num,p[i]%2)+1;
    }
    else{
        int l=1005,r=1005;
        if(k==2){
            if(odd_num!=0) l=dfs(i+1,odd_num-1,even_num,1);
            if(even_num!=0) r=dfs(i+1,odd_num,even_num,0);
        }
        else if(k==1){
            if(odd_num!=0) l=dfs(i+1,odd_num-1,even_num,1);
            if(even_num!=0) r=dfs(i+1,odd_num,even_num-1,0)+1;
        }
        else if(k==0){
            if(odd_num!=0) l=dfs(i+1,odd_num-1,even_num,1)+1;
            if(even_num!=0) r=dfs(i+1,odd_num,even_num-1,0);
        }
        dp[i][odd_num][even_num][k]=min(dp[i][odd_num][even_num][k]+l,dp[i][odd_num][even_num][k]+r);
    }
    return dp[i][odd_num][even_num][k];
}
int main(){
    n=read();
    rp(i,1,n){
        p[i]=read();
        if(p[i]) visited[p[i]]=1;
    }
    rp(i,1,n){
        if(!visited[i]){
            if(i%2==1) s1.pb(i);
            else s2.pb(i);
        }
    }
    mst(dp,-1);
    printf("%d\n",dfs(1,s1.size(),s2.size(),2));
    return 0;
}
/*
7
1 3 5 7 0 0 0
1
7
0 0 0 0 0 0 0 
1
7 
0 0 0 7 6 4 2
5
1 0 2 0 5
2
7
1 3 5 0 6 4 2
1
7
1 0 0 5 0 0 2
1
20
9 0 0 0 18 0 11 0 0 4 0 15 0 0 0 14 0 0 5 0
8
20
7 0 9 0 5 0 15 0 0 1 17 0 11 19 0 0 3 0 13 0
15
*/