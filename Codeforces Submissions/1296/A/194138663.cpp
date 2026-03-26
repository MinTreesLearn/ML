#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        int countOdd = 0 ,countEven = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] % 2 != 0)
            {
                countOdd++;
            }
            else countEven++;
        }

        if(countOdd == 0) cout<<"NO"<<endl;
        else if(countOdd % 2 != 0)cout<<"YES"<<endl;  
        else if(countEven>=1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
  	   	 		  		 	 	 						  		