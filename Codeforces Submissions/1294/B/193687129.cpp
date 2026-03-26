#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int tx, ty;
};
bool cmp(node a, node b)
{
	if(a.ty==b.ty)
	{
		return a.tx<b.tx;
	}
	else return a.ty<b.ty;
}
int n, flag;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, x, y, sz, nowx, nowy, nx, ny;
	string ans;
	cin>>T;
	while(T--)
	{
		vector<node>vtr;
		cin>>n;
		flag = 1;
		ans = "";
		nowx = nowy = 0;
		for(int i=1;i<=n;++i)
		{
			cin>>x>>y;
			vtr.push_back({x, y});
		}
		sort(vtr.begin(), vtr.end(), cmp);
		sz = vtr.size();
		for(int i=0;i<=sz-1;++i)
		{
			nx = vtr[i].tx;
			ny = vtr[i].ty;
			if(nx>=nowx&&ny>=nowy)
			{
				for(int j=1;j<=nx-nowx;++j)
				{
					ans += 'R';
				}
				for(int j=1;j<=ny-nowy;++j)
				{
					ans += 'U';
				}
			}
			else
			{
				flag = 0;
				break;
			}
			nowx = nx;
			nowy = ny;
		}
		if(!flag)
		{
			cout<<"NO"<<"\n";
		}
		else
		{
			cout<<"YES"<<"\n";
			cout<<ans<<"\n";
		}
	}
	return 0;
}