#include<bits/stdc++.h>
using namespace std;
#define long long long
int dp[101][101][101][4],a[102],n;
int ok(int ind,int ev,int od,int prev) {
    if(ind==n+1)
        return 0;
    if(dp[ind][ev][od][prev]!=-1)
        return dp[ind][ev][od][prev];
    int ans=1e4;
    if(a[ind]!=0) {
        int ex;
        if(prev!=3) {
            ex=(prev%2!=a[ind]%2);
        } else
            ex=0;
        ans=min(ans,ok(ind+1,ev,od,a[ind]%2)+ex);
    }
    else {
        int ex;
        if(ev>0) {
            if(prev!=3) {
                ex=(prev%2!=0);
            } else
                ex=0;
            ans=min(ans,ok(ind+1,ev-1,od,0)+ex);
        }
        if(od>0) {
            if(prev!=3) {
                ex=(prev%2!=1);
            }
            else
                ex=0;
            ans=min(ans,ok(ind+1,ev,od-1,1)+ex);
        }
    }
    return dp[ind][ev][od][prev]=ans;
}
int main() {
    cin>>n;
    memset(dp,-1,sizeof dp);
    int odd=0,even=0;
    set<int>st;
    for(int i=1;i<=n;i++){
        st.insert(i);
    }
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        if(a[i]>0)st.erase(st.find(a[i]));
    }
    for(auto t:st){
        if(t%2)odd++;
        else even++;
    }

    cout<<ok(1,even,odd,3)<<"\n";
}



  	 	  	  	 	   				  	 	 		