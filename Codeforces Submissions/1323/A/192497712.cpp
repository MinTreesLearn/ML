#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n==1 && arr[0]%2){
            cout<<-1<<'\n';
        }
        else{
            int ix=-1;
            for(int i=0;i<n;i++){
                if(arr[i]%2==0){
                   ix=i+1;
                   break;
                }
            }
            if(ix==-1){
                cout<<2<<'\n'<<1<<' '<<2<<'\n';
            }
            else{
                cout<<1<<'\n'<<ix<<'\n';
            }
        }
    }
    return 0;
}

		  	  				 		 	 	    				  		