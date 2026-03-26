#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#define fr(a, n) for(int i = a ; i < n ;++i)
#define fr2(a, n, i) for(int i = a ; i < n ;++i)

using namespace std;

void solve()
{
    int n; cin>>n;
    int arr[n];
    int left[n];
    int right[n];
    map<int, int> mp;
    set<int>st;
    fr(0, n)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    fr(1, 2 * n + 1)
    {
        if(mp[i] == 0)
            st.insert(i);
    }
    bool solved = false;
    fr(0, n)
    {
        auto it = st.begin();
        solved = false;
        while(it != st.end())
        {
            if(*it > arr[i] && !solved)
            {
                left[i] = arr[i];
                right[i] = *it;
                st.erase(it);
                solved = true;
                break;
            }
            it++;
        }
            if(!solved)
                break;
    }
    if(solved)
    {
        fr(0, n)
            cout<<left[i]<<' '<<right[i]<<' ';
        cout<<'\n';
    }
    else
        cout<<-1<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
        
        
    }
}


