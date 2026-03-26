#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i = a ; i < b ; i++)
#define read(x) int x ; cin>>x
#define yy cout<<"YES"<<endl;
#define nn cout<<"NO"<<endl;
using namespace std;

 
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

int main(){
	init_code();
	read(t);
	while(t--){
	read(n);
	int a[n];
	fr(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	fr(i,0,n){
		cout<<a[i]<<" ";
	}
	cout<<endl;
    }
	return 0;
}
