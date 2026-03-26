#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
const int mx=1e5;
int mob[maxn];
vector<int>d[maxn];
int turn[maxn];
int cnt[maxn];
int coprime(int x){
int ans=0;
for (auto v:d[x]){
    ans+=mob[v]*cnt[v];
}
return ans;
}
signed main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(nullptr);
	//freopen("usaco.INP","r",stdin);
    //freopen("usaco.OUT","w",stdout);
    mob[1]=1;
    for (int i=1;i<=mx;i++){
        for (int j=i*2;j<=mx;j+=i){
            mob[j]-=mob[i];
        }
    }
    for (int i=1;i<=mx;i++){
        if (mob[i]!=0){
            for (int j=i;j<=mx;j+=i){
                d[j].push_back(i);
            }
        }
    }
    int n;
    cin>>n;
    long long ans=0;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (turn[x])ans=max(ans,1ll*x);
        turn[x]=1;
    }
    for (int i=1;i<=mx;i++){
        vector<int>suzy;
        for (int j=(mx/i);j>=1;j--){
            if (turn[j*i]==0)continue;
            int cop=coprime(j);
            while (cop){
                int u=suzy.back();
                suzy.pop_back();
                if (__gcd(u,j)==1){
                    ans=max(ans,1ll*u*j*i);
                    cop--;
                }
                for (auto v:d[u]){
                    cnt[v]--;
                }
            }
            for (auto v:d[j])cnt[v]++;
            suzy.push_back(j);
        }
        while (!suzy.empty()){
            int u=suzy.back();
            for (auto v:d[u])cnt[v]--;
            suzy.pop_back();
        }
    }
    cout<<ans;
}


			  						  	   	 		 		 		