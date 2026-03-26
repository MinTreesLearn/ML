#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    int mini=1e18;
    int a=1,b=n;

    for(int i=1;i<=sqrt(n);i++){
    	if((i*(n/i))/(__gcd(i,n/i))==n){
    	if(min(max(i,n/i),mini)!=mini){
    		mini=(max(i,n/i));
    		a=i;
    		b=n/i;

    	}
    }
}

    cout<<a<<" "<<b;



 	   
    
    return 0;
}