#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,mx=0;
        bool flag=0;
        cin>>n>>x;
        for(int i=1;i<=n;i++){
            cin>>m;
            if(m==x){
                flag=1;
            }
            mx=max(mx,m);
        }
        if(flag){
            cout<<1<<endl;
        }
        else{
            cout<<max(2,(mx+x-1)/mx)<<endl;//向下取整
        }
    }
    return 0;
}
	 		   	  		 	  	   	   				