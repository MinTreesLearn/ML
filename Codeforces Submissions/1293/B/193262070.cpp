/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{      
    float n;
    cin>>n;
    float s=0.00000000000;
    for(float i=1;i<=n;i++){
        s+=(1/i);
    }
    cout<<s<<endl;
    return 0;
}
