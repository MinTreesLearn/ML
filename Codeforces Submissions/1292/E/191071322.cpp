// LUOGU_RID: 100771511
#define poj
//#define zcz
#ifdef poj
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<cassert>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
#ifdef zcz
class fastin{
	private:
#ifdef poj
	static const int MAXBF=1<<20;
#else
	const int MAXBF=1<<27;
#endif
	FILE *inf;
	char *inbuf,*inst,*ined;
	inline char _getchar(){
		if(inst==ined)inst=inbuf,ined=inbuf+fread(inbuf,1,MAXBF,inf);
		return inst==ined?EOF:*inst++;
	}
	public:
	fastin(FILE*_inf=stdin){
		inbuf=new char[MAXBF],inf=_inf,inst=inbuf,ined=inbuf;
	}
	~fastin(){delete inbuf;}
	template<typename Int> fastin&operator>>(Int &n){
		static char c;
		Int t=1;
		while((c=_getchar())<'0'||c>'9')if(c=='-')t=-1;
		n=(c^48);
		while((c=_getchar())>='0'&&c<='9')n=(n<<3)+(n<<1)+(c^48);
		n*=t;
		return*this;
	}
	fastin&operator>>(char*s){
		int t=0;
		static char c;
		while((c=_getchar())!=' '&&c!='\n')s[t++]=c;
		s[t]='\0';
		return *this;
	}
}fi;
class fastout{
	private:
#ifdef poj
	static const int MAXBF=1<<20;
#else
	const int MAXBF=1<<27;
#endif
	FILE *ouf;
	char *oubuf,*oust,*oued;
	inline void _flush(){fwrite(oubuf,1,oued-oust,ouf);}
	inline void _putchar(char c){
		if(oued==oust+MAXBF)_flush(),oued=oubuf;
		*oued++=c;
	}
	public:
	fastout(FILE*_ouf=stdout){
		oubuf=new char[MAXBF],ouf=_ouf,oust=oubuf,oued=oubuf;
	}
	~fastout(){_flush();delete oubuf;}
	template<typename Int> fastout&operator<<(Int n){
		if(n<0)_putchar('-'),n=-n;
		static char S[20];
		int t=0;
		do{S[t++]='0'+n%10,n/=10;}while(n);
		for(int i=0;i<t;++i)_putchar(S[t-i-1]);
		return *this;
	}
	fastout&operator<<(char c){_putchar(c);return *this;}
	fastout&operator<<(char*s){
		for(int i=0;s[i];++i)_putchar(s[i]);
		return *this;
	}
	fastout&operator<<(const char*s){
		for(int i=0;s[i];++i)_putchar(s[i]);
		return *this;
	}
}fo;
#define cin fi
#define cout fo
#else
#define czc ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#endif
#define mod 1000000007
#define ll long long
#define isinf 0x3f3f3f3f
#define ilinf 0x7fffffff
#define lsinf 0x3f3f3f3f3f3f3f3f
#define llinf 0x7fffffffffffffff
#define pii pair<int,int>
#define next ___
int n,t;
char s[60];
void solve1(){
	int x;
	cout<<"? CH\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1;i<=t;i++)cin>>x,s[x-1]='C',s[x]='H';
	cout<<"? CO\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1;i<=t;i++)cin>>x,s[x-1]='C',s[x]='O';
	cout<<"? CC\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1;i<=t;i++)cin>>x,s[x-1]=s[x]='C';
	if(s[0]=='C'){
		if(s[2]=='C'){
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
		}else{
			s[2]='O';s[3]='C';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//CCOC,CHOC,COOC
			}
			s[3]='O';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//CCOO,CHOO,COOO
			}
			s[3]='H';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//CCOH,CHOH,COOH
			}
			s[2]='H';s[3]='C';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//CCHC,COHC,CHHC
			}
			s[3]='O';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//CCHO,CHHO,COHO
			}
			s[3]='H';
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//CCHH,COHH,CHHH
		}
	}
	if(s[1]=='C'){
		s[0]='O';s[3]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OCCH,OCHH,OCOH
		}
		s[3]='C';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OCHC,OCCC,OCOC
		}
		s[3]='O';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OCHO,OCCO,OCOO
		}
		s[0]='H';s[3]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//HCCH,HCOH,HCHH
		}
		s[3]='C';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//HCCC,HCOC,HCHC
		}
		s[3]='O';
		cout<<"! "<<s<<'\n';
		cout.flush();
		return;
		//HCCO,HCHO,HCOO
	}
	if(s[2]=='C'){
		s[0]=s[1]='O';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OOCC,OOCO,OOCH
		}
		s[1]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OHCC,OHCO,OHCH
		}
		s[0]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//HHCC,HHCO,HHCH
		}
		s[1]='O';
		cout<<"! "<<s<<'\n';
		cout.flush();
		return;
		//HOCC,HOCO,HOCH
	}
	cout<<"? HO\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1;i<=t;i++)cin>>x,s[x-1]='H',s[x]='O';
	if(s[0]=='H'){
		if(s[2]=='H'){
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//HOHO
		}else{
			s[2]='O';s[3]='C';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//HOOC
			}
			s[3]='O';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//HOOO
			}
			s[3]='H';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//HOOH
			}
			s[2]='H';s[3]='C';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//HOHC
			}
			s[3]='H';
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//HOHH
		}
	}
	if(s[1]=='H'){
		s[0]='O';s[3]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OHOH
		}
		s[3]='C';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OHOC
		}
		s[3]='O';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OHOO
		}
		s[0]='H';s[3]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//HHOH
		}
		s[3]='C';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//HHOC
		}
		s[3]='O';
		cout<<"! "<<s<<'\n';
		cout.flush();
		return;
		//HHOO
	}
	if(s[2]=='H'){
		s[0]=s[1]='O';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OOHO
		}
		s[1]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1){
			cin>>x;
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OHHO
		}
		s[0]='H';
		cout<<"! "<<s<<'\n';
		cout.flush();
		return;
		//HHHO
	}
	cout<<"? OO\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1;i<=t;i++)cin>>x,s[x-1]=s[x]='O';
	if(s[0]=='O'&&s[1]=='O'){
		if(s[3]=='O'){
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OOOO
		}else{
			if(s[2]=='O'){
				s[3]='H';
				cout<<"? "<<s<<'\n';
				cout.flush();
				cin>>t;
				assert(t!=-1);
				if(t==1){
					cin>>x;
					cout<<"! "<<s<<'\n';
					cout.flush();
					return;
					//OOOH
				}
				s[3]='C';
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//OOOC
			}
			s[2]=s[3]='H';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1){
				cin>>x;
				cout<<"! "<<s<<'\n';
				cout.flush();
				return;
				//OOHH
			}
			s[3]='C';
			cout<<"! "<<s<<'\n';
			cout.flush();
			return;
			//OOHC
		}
	}
	s[1]=s[2]='H';
	cout<<"? HHH\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1;i<=t;i++)cin>>x,s[x-1]=s[x]=s[x+1]='H';
	if(s[0]==0)s[0]='O';
	if(s[3]==0)s[3]='C';
	cout<<"! "<<s<<'\n';
	cout.flush();
	//HHHH,HHHC,OHHH,OHHC
	return;
}
void solve(){
	cin>>n;
	fill(s,s+n+1,0);
	if(n==4){
		solve1();
		goto label;
	}
	cout<<"? CH\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1,x;i<=t;i++)cin>>x,s[x-1]='C',s[x]='H';
	cout<<"? CO\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1,x;i<=t;i++)cin>>x,s[x-1]='C',s[x]='O';
	cout<<"? CC\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1,x;i<=t;i++)cin>>x,s[x-1]=s[x]='C';
	cout<<"? HO\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1,x;i<=t;i++)cin>>x,s[x-1]='H',s[x]='O';
	cout<<"? OO\n";
	cout.flush();
	cin>>t;
	assert(t!=-1);
	for(int i=1,x;i<=t;i++)cin>>x,s[x-1]=s[x]='O';
	for(int i=1;i<n-1;i++)if(s[i]==0)s[i]='H';
//	cout<<s[0]<<' '<<s[n-1]<<'\n';
	if(s[0]!=0&&s[n-1]!=0){
//		cout<<'\t'<<1<<'\n';
		cout<<"! "<<s<<'\n';
		cout.flush();
		goto label;
	}
	if(s[0]!=0){
//		cout<<'\t'<<2<<'\n';
		s[n-1]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		int x;
		if(t==1)cin>>x;
		else s[n-1]='C';
		cout<<"! "<<s<<'\n';
		cout.flush();
		goto label;
	}
	if(s[n-1]!=0){
//		cout<<'\t'<<3<<'\n';
		s[0]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		int x;
		if(t==1)cin>>x;
		else s[0]='O';
		cout<<"! "<<s<<'\n';
		cout.flush();
		goto label;
	}
//	cout<<'\t'<<4<<'\n';
	s[0]='H',s[n-1]='C';
	cout<<"? "<<s<<'\n';
	cout.flush();
	cin>>t;
	assert(t!=-1);
	int x;
	if(t==1)cin>>x,cout<<"! "<<s<<'\n',cout.flush();
	else{
		s[0]=s[n-1]='H';
		cout<<"? "<<s<<'\n';
		cout.flush();
		cin>>t;
		assert(t!=-1);
		if(t==1)cin>>x,cout<<"! "<<s<<'\n',cout.flush();
		else{
			s[0]='O',s[n-1]='H';
			cout<<"? "<<s<<'\n';
			cout.flush();
			cin>>t;
			assert(t!=-1);
			if(t==1)cin>>x,cout<<"! "<<s<<'\n',cout.flush();
			else{
				s[0]='O',s[n-1]='C';
				cout<<"! "<<s<<'\n',cout.flush();
			}
		}
	}
	label:;
	cin>>x;
	assert(x==1);
	return;
}
int main(){
	#ifndef zcz
//	czc;
	#endif
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}