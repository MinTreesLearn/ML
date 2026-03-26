#include <bits/stdc++.h>
using namespace std;
int ans,n;
string f(string s,char c){
	int l=s.length();
	string tmp="";
	for(int i=0;i<l;i++){
		if(s[i]==c){
			int j=i+1;
			while(j<l&&s[j]==c) j++;
			if(i>0&&s[i-1]==c-1||j<l&&s[j]==c-1){
				ans+=j-i;
				i=j-1;
				continue;
			}
		}
		tmp+=s[i];
	}
	return tmp;
}
int main(){
	cin>>n;
	string s;
	cin>>s;
	for(char c='z';c>'a';c--)
		s=f(s,c);
	cout<<ans<<endl;
	return 0;
}