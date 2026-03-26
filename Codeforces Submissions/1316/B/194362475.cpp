#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define mod 1000000007
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t; cin>>t;
    while(t--){

    int n; cin>>n;
    string s;
    cin>>s;

    string b=s;
    sort(b.begin(), b.end());
    char mini=b[0];

    vector<int>pos;

    for(int i=0;i<n;i++){
    	pos.push_back(i);
    }

    if(b[0]==b[b.length()-1]){
    	cout<<s<<endl;
    	cout<<1<<endl;
    	continue;
    }

    vector<pair<string,int>>v;
    for(int i=0;i<pos.size();i++){

    	string temp=s.substr(pos[i],n);
    	string con=s.substr(0,pos[i]);

    	if(temp.size()%2==0){
    		temp+=con;
    	}
    	else{
    		reverse(con.begin(), con.end());
    		temp+=con;
    	}

    	v.push_back({temp,pos[i]+1});
    }

    sort(v.begin(),v.end());

    cout<<v[0].first<<endl;
    cout<<v[0].second<<endl;


    

    }

    
    
    return 0;
}