#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010

using namespace std;

int X, Y, N, Q, da_li, rez = 0;
vector <vector<int> > pos(3, vector <int> (MAXN));

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    while(Q--)
    {
        da_li = 0;
        cin >> X >> Y;
        if(pos[X][Y]) da_li++;
        else da_li--;
        pos[X][Y] ^= 1;
        for(int i = -1; i <= 1; i++) {if(i+Y >= 1 && i+Y <= N && pos[3 - X][Y + i]) rez += da_li;}
        if(rez == 0) {cout << "YES" << endl;}
        else {cout << "NO" << endl;}
    }
    return 0;
}
