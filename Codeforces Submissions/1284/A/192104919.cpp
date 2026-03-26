
// Depressed boy Bhaskor Roy
#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()

#define            pb                push_back
#define          sz(a)               (int)a.size()
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
void s1(){
int n,m;
cin>>n>>m;
string s[n],t[m];
forn(i,n)
    cin>>s[i];
forn(i,m)
    cin>>t[i];
int q;
cin>>q;
while(q--){
        int y;
        cin>>y;
        int i=y%n;
        if(i==0)
            i=n-1;
        else
            i=i-1;
        int j=y%m;
        if(j==0)
            j=m-1;
        else
            j=j-1;
            //cout<<i<<" "<<j<<endl;
        cout<<s[i]<<t[j]<<endl;

}



}



int main(){
    optimize();
int t;
s1();

return 0;
}
