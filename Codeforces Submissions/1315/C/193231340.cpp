#include <bits/stdc++.h>
#define range(i,n) for(int i= 0; i < (n); i++) 
typedef long long int ll;
#define arr(a,n)  for(int i=0;i<(n);i++) cin>>a[i];
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x)  x.begin(), x.end()
#define int ll
#define in insert
#define endl '\n'
using namespace std;
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
int testcase=1;
cin>>testcase;
for(int test=0;test<testcase;test++)
{
    int n;
    cin>>n;
    int a[n];
    arr(a,n);
    vector<int>b((2*n)+1,-1);
    vector<int>ans(2*n);
    queue<int> q;
    range(i,n){
        ans[2*i]=a[i];
        b[a[i]]=i;
    }
    int flag=0;
    for(int i=2*n;i>0;i--){
        if(b[i]==-1){
            q.push(i);
        }
        else{
            if(q.empty()){
                // cout<<-1;
                flag=1;
                break;
            }
            ans[2*b[i]+1]=q.front();
            q.pop();
        }
    }
    if(flag) cout<<-1; 
    else{
        for(int i=1;i<2*n;i+=2){
            for(int j=i+2;j<2*n;j+=2){
                if(ans[i]>ans[j] && ans[j]>ans[i-1] && ans[j-1]<ans[i]){
                    swap(ans[i],ans[j]);
                }
            }
        }
    range(i,2*n) cout<<ans[i]<<" ";
    }
    cout<<endl;
}

 return 0;
}