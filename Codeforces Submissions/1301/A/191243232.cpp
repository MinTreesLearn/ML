    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        long long int t;
        cin>>t;
        while(t--){
        	long long int n,i,a=0;
        	string str,str1,str2;
        	cin>>str>>str1>>str2;
        	n=str.size();
        	for(i=0;i<n;i++){
        		if(str[i]==str2[i] || str1[i]==str2[i]){
        		 	a++;
        		}
        	}
        	if(a==n){
        		cout<<"YES"<<endl;
        	}
        	else{
        		cout<<"NO"<<endl;
        	}
        }
        return 0;
    }