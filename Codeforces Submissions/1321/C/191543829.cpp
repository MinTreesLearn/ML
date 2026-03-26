#include<bits/stdc++.h>
#define ll long long int
#define debug(x) cout<<"x = "<<x<<endl;

using namespace std;
int fx[]= {1,-1,0,0,1,-1,1,-1};
int fy[]= {0,0,1,-1,1,-1,-1,1};
const ll MOD = 1e9+7;



void solve(int tt)
{

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>a[26];
    for(int i=0; i<n; i++)a[s[i]-'a'].push_back(i);
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    int cnt=0;
    set<int>st;
    for(char c='z'; c>'a'; c--)
    {
        for(int j=0; j<a[c-'a'].size(); j++)
        {

            int ind=a[c-'a'][j];
            if(st.find(ind)==st.end())
            {

                int k1=ind+1;
                int k2=ind-1;
                while(k1<n && (s[k1]==c || st.find(k1)!=st.end()))
                {
                    k1++;
                }
                while(k2>=0 && (s[k2]==c || st.find(k2)!=st.end()))
                {
                    k2--;
                }
                if(k1<n && s[k1]==(c-1))
                {
                    for(int k=ind; k<k1; k++)
                    {
                        if(st.find(k)==st.end())
                        {
                            st.insert(k);
                            cnt++;
                        }
                    }
                }
                else if(k2>=0 && s[k2]==(c-1))
                {
                    for(int k=ind; k>k2; k--)
                    {
                        if(st.find(k)==st.end())
                        {
                            st.insert(k);
                            cnt++;
                        }
                    }
                }
            }




        }

    }
    cout<<cnt<<endl;




}



int32_t main()
{
    //freopen("00_input.txt","r+",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int test=1;
    //cin>>test;
    for(int t=1; t<=test; t++)
    {
        solve(t);
    }
    return 0;

}

