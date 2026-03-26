#include<bits/stdc++.h>
using namespace std;

void res(){
 		long long a,c = 0;
        cin>>a;
        long long n[a];
        for( long long i = 1 ; i <= a ; i++ ){
            cin>>n[i];
            c+=(n[i]%2);
        }
        if( c==a || c==0)
        {
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
int main(){
	long long r;
	cin>>r;
	while(r--){
		res();
	}
	return 0;
}