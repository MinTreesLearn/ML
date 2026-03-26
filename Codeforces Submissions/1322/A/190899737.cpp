                                        /* God loves You */

#include<bits/stdc++.h>
using namespace std;
#define Sowrav_Nath ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f(i,n) for(int i=0;i<int(n);i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=int(n)-1;i>=0;i--)
#define rf1(i,n) for(int i = n;i>=1;i--)
#define saisir(v,x) int x; cin>>x; v.push_back(x);
#define le_debut int main
#define lol long long int
#define endl '\n'
#define pb push_back
#define un first
#define deux second
#define oui cout<<"YES"<<endl
#define non cout<<"NO"<<endl
#define homme cout<<"Bob"<<endl
#define femme cout<<"Alice"<<endl
#define un_de_minus cout<<"-1"<<endl
#define duck cout<<0<<endl;
#define reponse cout<<ans<<endl
#define ici cout<<"Je suis ici"<<endl
const int N = 2*1e5+10;
const int M = 1e9+7;



void allons_y(){

    int n; cin >> n;
    string s; cin >> s;
    vector<int>a;
    int res = 0, ans = 0;

    f(i,n){
        if(s[i] == '(') res++;
        if(s[i] == ')') res--;
        while(res < 0 && i < n){
            i++;
            if(s[i] == ')') res--;
            else {
                res++;
                ans += 2;
            }
            // cout << res << endl;
        }
        // cout << res << " " << i << endl;
    }

    res == 0 ? reponse : un_de_minus ;
}


le_debut(){
    Sowrav_Nath
    int t;
    t = 1;
    // cin >> t;
    while(t--){
        // memset(dp,0,sizeof(dp));
        allons_y();
    }
}