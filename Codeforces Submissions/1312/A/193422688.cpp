#include<bits/stdc++.h>


#define ll long long


using namespace std;


double  pi=3.1415926535897932384626433832795;
int fuc(int n){
    int sum=0;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    sum+=n%10;
    n/=10;
    return sum;
}
int  func(int n){
    int cnt;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            n/=i;
            return i;
        }
    }
    return n;
}
string toBinary(int n)
{
    string r;
    while(n!=0) {
        if(n%2==0){
            r+='0';
            n/=2;
        }
        else {
            r+='1';
            n/=2;
        }
    }
    return r;
}

///__builtin_popcount(ar[i]^ar[b]);
bool prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int func(int n,int m){
    int ans=1e9;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i<=m){
                ans=min(ans,n/i);
            }
            if(n/i<=m){
                ans=min(ans,i);
            }
        }
    }
    return ans;
}
/// long long  ar[int(1e6)];
void solve  ()
{
    int n,m;
    cin>>n>>m;
    if(n%m==0){
        cout<< "YES\n";
    }
    else{
        cout << "NO\n";
    }
}   
int main ()
{

    //for(long long  i=1;i<=sqrt(1e12);i++){ar[i]=1;}
        //for( long long i=2;i<=sqrt(1e12);i++){if(ar[i]!=0){ar[i]=i*i;for( long long j=i*i;j<=sqrt(1e12);j+=i){ar[j]=0;}}}




    int t;
    cin>>t;
    while(t--){
        solve ();
    }
}