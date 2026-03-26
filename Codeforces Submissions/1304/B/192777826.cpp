#include<bits/stdc++.h>
#define int long long
#define fa(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define bp pop_back
// #define mp make_pair
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int ispali(string str)
{
    int s=0,p=str.length()-1;
    while(s<=p)
    {
        if(str[s]!=str[p])
            return 0;
        s++,p--;
    }
    return 1;
}
void solve(){
    int n,m;
    cin >> n >> m;
    map<string,int> mp;
    vector<string> a(n);
    string s1="",s2="",s3="";
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(mp[a[i]])
        {
            string t=a[i];
            mp[a[i]]--;
            reverse(t.begin(),t.end());
            if(mp[t])
            {
                s1.append(a[i]);
                s2.append(t);
                mp[t]--;
            }
            else if(s3.length()==0 && ispali(a[i]))
            {
                s3.append(a[i]);
            }
        }
    }
    s2=s1;
    reverse(s2.begin(),s2.end());
    cout << s1.length()+s3.length()+s2.length() << endl;
    cout << s1<<s3<<s2 << endl;
    return;
}
signed main()
{
    faster;
    int t=1;
    //cin>>t;
    while(t--)
    solve();
}