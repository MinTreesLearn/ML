#include<bits/stdc++.h>
#define ll long long
#define mod (ll)1000000007
using namespace std;
unordered_map<string,vector<int>> f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;

    string s;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin>>s;
        f[s].push_back(i);
        a[i] = s;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            
            // cout<<"a[i]:"<<a[i]<<",a[j]:"<<a[j]<<"\n";
            string t = "";
            for(int p = 0; p < k; p++){
                int S = 0, E = 0, T= 0;
                if(a[i][p] == 'S')
                    S++;
                else if(a[i][p] == 'E') E++;
                
                else 
                    T++;

                if(a[j][p] == 'S')
                    S++;
                else if(a[j][p] == 'E')
                    E++;
                else
                    T++;

                // cout<<"S:"<<S<<",T:"<<T<<",E:"<<E<<"\n";

                if(S == 2){
                    t+='S';
                }
                else if(T == 2){
                    t+='T';
                }     
                else if(E == 2){
                    t+= 'E';
                }

                else if(S == 1 && E == 1){
                    t += 'T';
                }
                else if(S == 1 && T == 1){
                    t+='E';
                }
                else
                    t+='S';
            }

            // f[a[i]]--;
            // f[a[j]]--;

            if(f.find(t) != f.end()){
                
                int ft = upper_bound(f[t].begin(),f[t].end(),j) - f[t].begin();

                ans += (int)f[t].size()-ft;

            }

            // cout<<"t:"<<t<<"\n";
            // f[a[i]]++;
            // f[a[j]]--;
        }
    }

    cout<<ans<<"\n";
    return 0;
}