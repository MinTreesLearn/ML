#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

typedef unsigned long long ull;
typedef pair<int,int> PII;

void Dbug(string s,int x){
    cout<<"DEBUG:"<<s<<" "<<x<<"\n";
}
void Dbug(int x){
    cout<<"DEBUG:"<<x<<"\n";
}

const int N=2e5+10,mod=1e9+7;

int n,m;
string s;
int sum[N][30];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>s;
    n=s.size();
    cin>>m;
    s='?'+s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            sum[i][j]=sum[i-1][j];
        }
        sum[i][s[i]-'a'+1]++;
    }
    for(int _=1,l,r,cnt;_<=m;_++){
        cin>>l>>r;
        if(l==r||s[l]!=s[r]){
            cout<<"Yes\n";
            continue;
        }
        cnt=0;
        for(int i=1;i<=26;i++){
            if(sum[l-1][i]<sum[r][i]){
                cnt++;
            }
        }
        cout<<(cnt>2?"Yes":"No")<<endl;
    }
    return 0;
}

 	 		 	  	   			  	 	 	  						