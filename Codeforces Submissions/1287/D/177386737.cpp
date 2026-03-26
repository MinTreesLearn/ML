#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2010;
int n,c[N],a[N],Num[N];
bool vis[N],sign;
vector<int>pic[N];
  int root,parent;
void dfs(int num)
{
    if(!sign)
      return;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])//没用过这个数
            cnt++;
        if(cnt==c[num]+1)
        {
            a[num]=i;
            vis[i]=1;//every time use one，避免难以判断的s b情况出现 
            break;
        }
    }
    for(int i=0;i<pic[num].size();i++)//计算子节点的数量
    {
        dfs(pic[num][i]);
        Num[num]+=Num[pic[num][i]];
    }
    if(Num[num]<c[num])//如果子节点数量小于需求数  return ，标记一下输出 NO
    {
        sign=0;
        return;
    }
}
int main()
{
     cin>>n;
        for(int i=1;i<=n;i++)
        {
          cin>>parent>>c[i];
            if(parent==0)
                root=i;
            else
           pic[parent].push_back(i);//父节点为parent，自己的编号为i。
        }
        for(int i=1;i<=n;i++)
         {  Num[i]=pic[i].size();}
        sign=1;
        dfs(root);
        if(sign)
        {
          cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
               cout<<a[i]<<" ";
               cout<<endl;
        }
        else
           cout<<"NO";
    
    return 0;
}


       						      	 	 					