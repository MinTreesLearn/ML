#include<bits/stdc++.h>
using namespace std;
#define int  long long int 
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(a) a.begin(), a.end()
#define mp make_pair
const char nl = '\n';

int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){ if(a<b)return a;return b;}
int gcd(int a, int b) { return b?gcd(b,a%b):a;}  
int lcm(int a, int b) { return a/gcd(a,b)*b;} 

int computeXOR(int n)
{if (n % 4 == 0)  return n; if (n % 4 == 1) return 1; if (n % 4 == 2)   return n + 1; return 0;}
 main()  {
int t;
cin>>t;
while(t--) {
int n;
cin>>n;
int v1[n];
map<int,int>mp1;
map<int,int>mp2;
bool flag = false;
for(int i=0;i<n;i++) {
cin>>v1[i];

}

for(int i = 0;i<n-2;i++) {
    for(int j = i+2;j<n;j++) {
        if(v1[i] == v1[j])
        {
            flag = true;
            break;
        }
    }
    if(flag == true)break;
}


if(flag) {cout<<"YES"<<nl;}
else{
    cout<<"NO"<<nl;
}

}
return 0;
}
