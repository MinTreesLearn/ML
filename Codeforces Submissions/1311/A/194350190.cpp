#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a<b){
			int x=b-a;
			if(x%2==0){
				cout<<2<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
		else if(a==b){
			cout<<0<<endl;
		}
		else{
			int h=a-b;
			if(h%2==0){
				cout<<1<<endl;
			}
			else{
				cout<<2<<endl;
			}
		}
	}
	
	return 0;
}