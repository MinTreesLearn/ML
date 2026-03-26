#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long int ll;
const int N = 1e5+9;
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    map<char, vector<int>> mp;
    for(int i=0;i<s1.size();i++)
    {
        mp[s1[i]].push_back(i+1);
    }

    int cnt = 1, val = 1;
    for(int i=0;i<s2.size();i++)
    {
        if(mp.find(s2[i]) == mp.end()) 
        {
            cout << -1 << "\n";
            return;
        }
        else
        {
            auto pos = lower_bound(mp[s2[i]].begin(), mp[s2[i]].end(), val);
            if(pos == mp[s2[i]].end())
            {
                cnt++;
                val = *lower_bound(mp[s2[i]].begin(), mp[s2[i]].end(), 0)+1;
            }
            else
            {
                val = *pos+1;
            }
            //cout << val << "\n";
        }
    } 
    cout << cnt << "\n";
} 
int main()
{
    FAST;
    int t = 1, cs = 1;
    cin >> t;
    while(t--)
    {
        //cout << "Case " << cs++ << ":\n";
        solve();
    }
    return 0;
}
		 	 			   				 	    			   			