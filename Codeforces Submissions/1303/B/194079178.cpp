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

    int t; cin>>t;
    while(t--){

    	int n,g,b;
    	cin>>n>>g>>b;
    	if(g>=n){
    		cout<<n<<endl;
    		continue;
    	}

    	int min_good=(n+1)/2;
    	int max_bad=(n)/2;

    	if(g>=min_good){
    		cout<<n<<endl;
    		continue;
    	}
    	if(g>=b){
    		cout<<n<<endl;
    		continue;
    	}
    		
    	if(min_good%g==0){
	    	int turns=min_good/g;
	    	int ans=min_good+(turns-1)*b;
	    	ans=max(ans,n);
	    	cout<<ans<<endl;
    	}
    	else{
	    	int turns=(min_good)/g; 
	    	int ans=min_good;
	    	ans+=turns*b;
	    	ans=max(ans,n);
	    	cout<<ans<<endl;
    		}
    }
    	
    return 0;
}