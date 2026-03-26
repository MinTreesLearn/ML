#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    
    int ok=1;
    for(int i = 0; i < n;i++){
        int small = 0,big = 0;
        for(int j = 0; j< i;j++)
            if(s[j] > s[i]) small=1;
        for(int j = i+1;j < n;j++)
            if(s[j] < s[i]) big=1;
            
        if(small && big) ok = 0;
    }
    
    if(!ok) {cout<<"NO\n";return;}
    cout<<"YES\n";
    string ans(n,'0');
    
    for(int i = 0;i < n;i++){
        int cur = 1;
        for(int j = 0; j<i;j++)
            if(s[j]>s[i]) cur=0;
        if(!cur)ans[i]='1';
    }
    
    cout<<ans;
}     


int main(){
   ios_base::sync_with_stdio(0),cin.tie(0);
   int t=1;//cin>>t;
   while(t--) solve();
}


/*
its impossible if there exists a character that has to 
be swapped left itself, and another that has to be swapped
even more left than it 
e.g. if for some character c_i at index i, there exists 
character c_j, such that c_i < c_j and j < i and also
theres a c_k, such that c_i > c_k and k > i

abacbecfd
001010100

i think its fine if we mark any character that doesnt have to move 
0 and the rest 1 
e.g. if for prefix i, all character on 1..i-1 <= to c_i
*/