#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
void ONLINE();
void clion();
bool cmp (pair<int,int> &a , pair<int,int> &b)
{
    return a.first < b.first;
}
#define FIXED 100001
int main(){
    //ONLINE();
    //clion();
    FAST;
    //vector<pair<int,int>>v{{0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};
    //sort(v.begin(),v.end(),cmp);
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        if(n == 2)
        {
            cout << 1 << "\n";
        }else if(n == 3)
        {
            cout << "7\n";
        }else
        {
            if(n % 2 == 1)
            {
                cout << "7";
                n -= 3;
            }
            for(int i = 1; i <= n ;i+=2)
            {
                cout << 1;
            }
            cout << "\n";
        }
    }

    return 0;
}

void clion() {
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
}

void ONLINE(string name = "cowsignal") {
    if ((name.size())) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}