    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
   	  long long int t;
   	  cin>>t;
   	  while(t--){
        	long long int n,m,a,b,i,mx=0,xd=0,yd=0,dl=0;
        	cin>>n;
        	long long int arrx[2001][2],arra[2001],arr[n],k;
        	string str;
        	memset(arra,0,sizeof arra);
        	for(i=0;i<n;i++){
        		cin>>a>>b;
        		m=a+b;
        		arr[i]=m;
        		arrx[m][0]=a;
        		arrx[m][1]=b;
        		arra[m]++;
        		if(arra[m]==2){
        			dl=1;
        		}
        	}
        	if(dl==1){
        		cout<<"NO"<<endl;
        	}
        	else{
        		dl=0;
        		sort(arr,arr+n);
        		for(i=0;i<n;i++){
        			m=arr[i];
        			a=arrx[m][0]-xd;
        			b=arrx[m][1]-yd;
        			if(a<0 || b<0){
        				dl=1;
        			}
        			for(k=0;k<a;k++){
        				str +='R';
        			}
        			for(k=0;k<b;k++){
        				str +='U';
        			}
        			xd=arrx[m][0];
        			yd=arrx[m][1];
        		}
        		if(dl==0){
        			cout<<"YES"<<endl;
        			cout<<str<<endl;
        		}
        		else{
        			cout<<"NO"<<endl;
        		}
        	}
        }
        return 0;
    }