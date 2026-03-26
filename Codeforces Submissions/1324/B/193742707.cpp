/**https://userpic.codeforces.org/2328346/title/fbb135ec547634e3.jpg
https://userpic.codeforces.org/2328346/title/fbb135ec547634e3.jpg
https://userpic.codeforces.org/2328346/title/fbb135ec547634e3.jpg**/
////////////////////////////////////////////////////////
///                                                   //
///            CODE BY                                //
///                   RAHAPAHA                        //
///                                                   //
////////////////////////////////////////////////////////
#include <bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define exit return 0;
#define out break;
#define Ferarri ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;
using namespace std;
vector<int> g[101];
queue<int>q;
vector<int>us(101);
vector<int> p(101);
/*void bfs(int v){
    q.push(v);
    us[v] = 1;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for (int i: g[v]) {
            if (!us[i])
            {
                q.push(i);
                p[i] = v;
                us[i] = 1;
            }
        }
    }
}
*/
void solve(){

}
int main()
{
    Ferarri
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        map<int,int>mp;
        map<int,bool>mp2;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i-1]==a[i] && !mp2[a[i]] && i>0){
                mp[a[i]]--;
                mp2[a[i]]=1;
            }
            mp[a[i]]++;
        }
        bool k=0;
        for(int i=0;i<n;i++){
            if(mp[i+1]>=2){
                cout<<"YES";
                k=1;
                break;
            }
        }
        if(!k){
            cout<<"NO";
        }
        cout<<"\n";
    }
}

