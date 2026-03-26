#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int,int> m;
    m[1] = 2;
    m[2] = 5;
    m[3] = 5;
    m[4] = 4;
    m[5] = 5;
    m[6] = 6;
    m[7] = 3;
    m[8] = 7;
    m[9] = 6;
    m[0] = 6;
    int n,f;
    string s;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        s = "";
        f = 0;
        int tmp;
        cin>>tmp;
        int res = tmp/2;
        if(tmp%2 == 1)
        {
            res -=1;
            f = 1;
        }
        for(int j = 0; j < res; j++)
        {
            s += "1";
        }
        if(f)
            s = "7" + s;
        cout<<s<<endl;
    }
    return 0;
}
