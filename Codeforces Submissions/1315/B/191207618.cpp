#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a , b , p;
    cin >> a >> b >> p;
    string s;
    vector<pair<int , int>> ab;
    cin >> s;
    long long tcost =0 , cost;
    int i = 0;
    int n = s.size();
    while(i < n-1)
    {
        tcost += s[i] == 'A' ? a : b;

        cost = s[i] == 'A' ? a : b;
        char same = s[i];
        int saved = i;
        while(s[i] == same)
            i++;
        ab.push_back({saved , cost});
    }
    if(p >= tcost)
    {
        cout << 1 << endl;
        return;
    }
    for(int i = 0; i < ab.size(); i++)
    {
        // cout << ab[i].first <<" "<<  ab[i].second <<" " <<cost << endl;
        if(p >= tcost)
        {
            cout << ab[i].first+1 <<endl;
            return;
        }
        tcost -= ab[i].second;
    }
    cout << n << endl;
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int t = 1;
	cin >> t;
    while(t-- > 0 ) solve();
}
