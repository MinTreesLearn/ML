#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		int cnt=0;
		for(int i=0;i<s1.size();i++){
			swap(s1[i],s3[i]);
			if(s1[i]==s2[i])cnt++;
			else{
				swap(s1[i],s3[i]);
				swap(s2[i],s3[i]);
				if(s1[i]==s2[i])cnt++;
			}
		}
		if(cnt==s1.size())
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
}
