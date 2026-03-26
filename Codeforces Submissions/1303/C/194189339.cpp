 //ANY TIME YOU SEE OPTIMIZATION PROBLEM -> BINARY SEARCH THE ANSWER!!!

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define No cout<<"No"<<endl; 
#define NO cout<<"NO"<<endl;  
#define Yes cout<<"Yes"<<endl; 
#define YES cout<<"YES"<<endl; 
#define MOD 1000000007
#define endl '\n'
 

void solve()
{ 
  ll n, i, j, flag =0;
  string s;
  cin>>s;
  map<char, ll> mp;
  deque<char> dq;
  deque<char>::iterator it;

  dq.push_back(s[0]);
  it = dq.begin();
  mp[s[0]]++;
  for(i=1;i<s.size();i++)
  {
    if(mp[s[i]]==0)
    {
      if(it == dq.begin())
      { 
        
        dq.push_front(s[i]);
        it = dq.begin();
      }
      else if(it+1 == dq.end())
      {
        dq.push_back(s[i]);
        it = dq.end()-1;
      }
      else
      { 
        //cout<<*it<<endl;
        NO
        flag=1;
        break;
      }
      mp[s[i]]++;
    }
    else
    {
      if(it==dq.begin())
      {
        if(*(it+1)==s[i])
        {
          it = it +1;
        }
        else
        { 
          //cout<<s[i]<<endl;
          NO
          flag=1;
          break;
        }
      }
      else if(it == dq.end()-1)
      {
        if(*(it-1)==s[i])
        {
          it = it - 1;
        }
        else
        {
          NO
          flag=1;
          break;
        }
      }

      else
      { 
        auto it1 = it + 1;
        auto it2 = it-1;
        if(*(it1)==s[i])
        {
          it = it1;
        }
        else if(*(it2)==s[i])
        {
          it = it2;
        }
        else
        {
          NO
          flag = 1;
          break;
        }
      }
    }
  }

  if(flag==0)
  {
    YES

    for(auto it: dq)
    {
      cout<<it;
    }
    for(char i='a';i<='z';i++)
    {
      if(mp[i]==0)
      {
        cout<<i;
      }
    }

    cout<<""<<endl;
  }
  else
  {

  }
  
}

   


 
 int main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--)
    solve();
  }