#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int sum = 0, even = 0, odd = 0;
        vector<int> arr(a);
        for (int j = 0; j < a; j++)
        {
            cin >> arr[j];
            sum += arr[j]; 
        }
        if(sum%2 == 1)
        {
            cout << "YES" << endl;
            
        }
        else
        {
            for (int j = 0; j < a; j++)
            {
                if(arr[j]%2 == 0)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
            if(even != 0 && odd != 0){
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
            
        


        
    }
    
    

}