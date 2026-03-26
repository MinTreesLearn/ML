#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n,a;
	bool o=0,e=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n%2==0){
			for(int j=0;j<n;j++){
				cin>>a;
				if(a%2==0){
					e=1;
				}
				else{
					o=1;
				}
			}
			if(o && e){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			o=0;
			e=0;
		}
		else{
			for(int j=0;j<n;j++){
				cin>>a;
				if(a%2==1){
					o=1;
				}
			}
			if(o){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			o=0;
		}
	}
}
