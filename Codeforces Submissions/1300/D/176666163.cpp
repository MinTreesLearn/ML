#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//解除绑定
ll x[100005],y[100005];
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i]>>y[i];
    }
    if(n%2){
        cout<<"no"<<endl;
        return 0;
    }
    int k=0;
    ll q=x[1]+x[n/2+1],w=y[1]+y[n/2+1];
    for(int i=1;i<=n/2;i++)
    {
        if((x[i]+x[n/2+i]!=q)||(y[i]+y[n/2+i]!=w))
        {
            k=1;
            break;
        }
    }
    if(k==0)
        cout<<"yes";
    else
        cout<<"no";

    
    return 0;
}

  	 	 	 				 	        		 		  		