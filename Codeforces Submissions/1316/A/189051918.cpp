#include <iostream>
#include <cstring>
#include <algorithm>
const int N=5e5+10;
int a[N];
using namespace std;

int main()
	{
	int t;
	cin>>t;
	while(t--)
		{

		int n,m,i,j,sum=0;
		cin>>n>>m;

		for(i=0; i<n; i++)
			{
			cin>>a[i];
			sum+=a[i];
			}

		cout<<min(sum,m)<<endl;
		}
	return 0;
	}
 						  			     		  					  			