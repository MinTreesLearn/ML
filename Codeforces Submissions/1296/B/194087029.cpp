#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
	long long t,s;
	cin>>t;
	while(t--){
		cin>>s;int sum=s;
		while(s>9){
			int k=s%10;
			s=s/10;
			sum=sum+s;
			s=s+k;
		}
		cout<<sum<<endl;
	}
	return 0;
}