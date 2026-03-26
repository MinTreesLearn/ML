#include<bits/stdc++.h>
#define x first
#define y second
#define endl '\n'
#define LL long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=200010,MOD=1e9+7;
typedef pair<int,int> PII;
int e[N],ne[N],h[N],w[N],idx=0;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
LL qpow(LL a,LL b){
	LL res=1;
    while(b>0){
		if(b&1)	res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
LL ans,n,num,x;
string s,s1,t;
int main()
{
	ios;
	cin>>n;
    cin>>s;
    if(n&1){
    	cout<<"-1"<<endl;
    	return 0;
    }
    bool f=0;
    for(int i=0;i<s.size();i++){
    	if(s[i]=='(') x++,num++;
    	else if(s[i]==')'){
    		x--;
    		if(x<0) f=1;
    	}
    	if(x==0){
    		if(f)ans+=num*2;
    		f=num=x=0;
    	}
    }
    if(x!=0) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}

    	   		 			 	   		 			  	 		