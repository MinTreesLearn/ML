#include<bits/stdc++.h>
using namespace std;
#define int long long

 


  const int M=998244353;;
        long long mod(long long x){
            return ((x%M + M)%M);
        }
        long long add(long long a, long long b){
            return mod(mod(a)+mod(b));
        }
        long long mul(long long a, long long b){
            return mod(mod(a)*mod(b));
        }
        
 long long modPow(int x, int y){
    if(y==0) return 1LL;
    if(y==1) return mod(x);
    long long res=1;
    while(y){
        if(y%2==1)
            res=mul(res,x);
        x=mul(x,x);
        y/=2;
    }
    return res;
}
int pow(int x, int n, int d) {
   int M=d;
    if(x==0)
        return 0;
    return modPow(x,n);
}
    
void solve(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	if(m==0){
		cout<<0<<endl;
		return;
	}
	int s= (n*(n+1))/2;
	int x=n-m;//no of zeros in the string
	int g1=x/(m+1);
	int y=x%(m+1);
		//cout<<y<<" ";
	int res=0;
	int z=g1+1;	
	z=(z*(z+1))/2;
	z*=y;
//	cout<<g1<<" ";
	int z2=g1;	
		z2=(z2*(z2+1))/2;
		z2*=(m+1-y);
		 res=z+z2;
		cout<<s-res<<endl;
		return;
	//cout<<y<<endl;
/*	for(int j=1;j<=(m+1);j++){
		if(y>0){
		
		res+=z;
		y--;
		}else{
		
		res+=z;
		}
		
		
	}
	
	cout<<s-res<<endl;*/
	
	}
	
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
  int t;
 cin>>t;
  while(t--){
        solve();
        }
    }