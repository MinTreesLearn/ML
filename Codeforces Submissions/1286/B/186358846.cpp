#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e3+5;
vector<int>g[maxm];
int c[maxm];
int res[maxm];
int n;
vector<int> dfs(int now){
    vector<int>res;//存子节点
    for(int x:g[now]){
        vector<int>ch=dfs(x);
        for(int v:ch){
            res.push_back(v);
        }
    }
    if(c[now]>res.size()){//如果没法插入说明不可能
        cout<<"NO"<<endl;
        exit(0);
    }
    res.insert(res.begin()+c[now],now);//插到中间
    return res;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int fa;
        cin>>fa;
        cin>>c[i];
        g[fa].push_back(i);
    }
    vector<int>ans=dfs(0);//0是虚根
    for(int i=0;i<(int)ans.size();i++){//节点赋值
        res[ans[i]]=i;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){//输出答案
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return 0;
}

 		  		 		 	  		  				    	 			