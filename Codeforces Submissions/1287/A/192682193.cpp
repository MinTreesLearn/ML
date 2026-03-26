#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        string s;
        int ans=0,count=0;
        cin>>m;
        cin>>s;
        for(int i=m-1;i>=0;i--){
            if(s[i]=='P'){
                count++;
            }
            else{
                ans = max(ans, count);
                count=0;
            }
    }
    cout<<ans<<"\n";
}
}
	    	 	 				   			 	 	    	 	