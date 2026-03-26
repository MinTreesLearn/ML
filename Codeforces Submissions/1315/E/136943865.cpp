#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(1<<17)+10;
unordered_map<int,int>mp[4][maxn];

int fav[maxn];
int dfs(int l,int r,int s){
    if(r==l+1){
        int num1=fav[l]+fav[r],num2=(s&1)+(s>>1); 
        if(num1==num2){
            return min(1,num2); 
        }
        else return -1e6; 
    }
    if(mp[s][l].count(r)){
        return mp[s][l][r]; 
    }
    int ans=-1e6,mid=l+r>>1; 
    for(int i=0;i<4;i++){
         for(int j=0;j<4;j++){
             int ilose=((i&2)|(i<<1)|j)&3,jlose=((j&2)|(j<<1)|i)&3;
             if(s==ilose||jlose==s) ans=max(ans,dfs(l,mid,i)+dfs(mid+1,r,j)); 
         }
    }
    return mp[s][l][r]=ans+s; 
}
int main(){
     
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&x),fav[x]=1;
    int ans=0;
    for(int i=0;i<4;i++)
        ans=max(ans,dfs(1,1<<n,i));
    printf("%d\n",ans+(m?1:0));//最后赢和输还有一场对决
 
    return 0; 
}