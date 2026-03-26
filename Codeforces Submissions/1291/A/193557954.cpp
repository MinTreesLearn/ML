//jai shree ram 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long long LL;
typedef long double ld;
typedef vector<long long> vLL;
typedef vector<long long int> vll;
typedef vector<int> vi;
#define pb push_back
#define mk make_pair

int bisearch(ll arr[],ll x,int n){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==x){
            return mid;
 
        }
        else if(arr[mid]>x){
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return -1;
}
 

int cntDistinct(string str)
{
    unordered_set<char> s;
 
    for (int i = 0; i < str.size(); i++) {
 
        s.insert(str[i]);
    }
 
    return s.size();
}


int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
string s;
cin>>s;
int a[2];
int k=0;
for(int i=0;i<n;i++){
 if((s[i]-'0')%2==1){
    a[k]=s[i]-'0';
    k++;
 }
 if(k==2)break;
}
if(k==2)cout<<a[0]<<a[1];
else cout<<"-1";
cout<<endl;
}

    return 0;
}

//jai shree krishna 