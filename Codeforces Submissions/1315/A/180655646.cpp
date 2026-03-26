#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &a , const int &b) {
    return a > b ; 
}
int main(){
	int t=0;
	cin>>t;
	
	while(t){
	    int a[4];
		for(int q=0;q<4;q++){
			cin>>a[q];
		}
		int b[4]={0,0,0,0};
		b[0]=abs(0-a[2])*a[1];
		b[1]=abs(0-a[3])*a[0];
		b[2]=(a[0]-1-a[2])*a[1];
		b[3]=(a[1]-1-a[3])*a[0];
		sort(b,b+4,cmp);
		cout<<b[0]<<endl;
		t--;
	}
	
	return 0;
}
	 		   		 	  	 	 	  	  	  		 		