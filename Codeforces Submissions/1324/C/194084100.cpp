#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 2e5 + 5;
int b[N];
void solve()
{
	string a;
	cin>>a;
	int len = a.size();
	b[1] = 0;
	int idx = 1;
	for(int i = 0; i < len; i++)
	{
		if(a[i] == 'R') b[++idx] = i + 1;
	}
	b[++idx] = len + 1;
	int g = 0;
	for(int i = 2; i <= idx; i++)
	{
		g = max(g, b[i] - b[i - 1]);
	}
	cout<<g;
	cout<<'\n';
} 

int main()
{
	std::ios::sync_with_stdio(false);
 	int t;
    cin>>t;
 	while(t--)
    {
        solve();
    }
	
//	solve();
}

