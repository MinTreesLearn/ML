#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n;
    int x;
    cin>>x;
    while(x--){
        int k=0;
        cin>>n>>k;
        int s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
		for(int i=1;i<=k;i++){
			for(int j=2;j<=n;j++){
				if(a[j]>0){
					a[j]--;
                    a[j-1]++;
					break;
				}
			}
		}
		cout<<a[1]<<endl;
	}
    return 0;
}
 				 	 	   		    	 				  	  	