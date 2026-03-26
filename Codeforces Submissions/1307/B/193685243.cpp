/* Ψ In Search Of An Equilibrium Ψ */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n" 
#define lp(i, a, b) for (int i = a; i < b; i++)
#define lpp(i, a, b) for (int i = a; i <=b; i++)
#define print(arrrr) lp(i,0,n) cout << arrrr[i] << " "
#define scan(arrrr) lp(i,0,n) cin >> arrrr[i]
#define pi pair<int, int>
#define vs vector<string>
#define vi vector<int>
#define all(arr) arr.begin(), arr.end()
#define srt sort(arr,arr+n,greater<int>());
#define F first
#define S second
#define yes cout << "YES"<<"\n" ;
#define no cout << "NO"<<"\n" ;
#define ll long long int
#define int int64_t

void solve()
{
int n,x;cin>>n>>x;
int arr[n];scan(arr);
lp(i,0,n){
    if(arr[i]==x) {cout<<1<<endl;return;}
}
sort(arr,arr+n);
int ans=0;
ans+=(x%arr[n-1]!=0?(x/arr[n-1])+1:(x/arr[n-1]));
ans=0?ans++:ans;
if(arr[n-1]>x) ans++;
cout<<ans<<endl;
}

int32_t main()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int t=1 ;
cin >> t ; 
while(t--)
{
solve();
}

}
