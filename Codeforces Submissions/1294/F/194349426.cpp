//ashrafsusts19



#include <bits/stdc++.h>
#include <limits>

using namespace std;
typedef long long int lli;
#define prnt(a) cout << a << "\n"
#define prnt2(a, b) cout << a << " " << b << "\n";
#define prnt3(a, b, c) cout << a << " " << b << " " << c << "\n";
#define forp1(a) for (lli i = 0; i < a; i++)
#define forp2(a, b) for (lli i = a; i < b; i++)
#define forf(a, b, c) for (lli i = a; i < b; i += c)
#define forv1(i, a) for (lli i = 0; i < a; i++)
#define forv2(i, a, b) for (lli i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define refill(a, b, c) a.clear();a.resize(b, c);
#define reloc(a, b) a.clear();a.resize(b);


void debug(vector<lli> &lst){
    cout << "Debug: ";
    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";    
    cout << "\n";
}

void debug2(string name, vector<lli> &lst)
{
    cout << name << ": ";
    for (lli i = 0; i < lst.size(); i++) cout << lst[i] << " ";
    cout << "\n";
}


lli n;
vector<vector<lli>> roads;
vector<vector<pair<lli, lli>>> premx, sufmx, lmx;
lli a = -1, b = -1, c = -1, mxcnt = 0;


pair<lli, lli> dfs(lli ind, lli parent){
    lli rn = roads[ind].size();
    premx[ind].resize(rn + 2, {-1, -1});
    sufmx[ind].resize(rn + 2, {-1, -1});
    lmx[ind].resize(rn, {-1, -1});
    pair<lli, lli> mxd = {0, ind};
    for (lli i = 0; i < roads[ind].size(); i++){
        lli cind = roads[ind][i];
        if (cind == parent) continue;
        pair<lli, lli> p = dfs(cind, ind);
        lmx[ind][i] = p;
        premx[ind][i + 1] = p;
        sufmx[ind][i + 1] = p;
        mxd = max(mxd, p);
    }
    mxd.first++;
    return mxd;
}


void fndfs(lli ind, lli parent, pair<lli, lli> prev){
    for (lli i = 0; i < roads[ind].size(); i++){
        if (roads[ind][i] == parent){
            lmx[ind][i] = prev;
            premx[ind][i + 1] = prev;
            sufmx[ind][i + 1] = prev;            
        }
        premx[ind][i + 1] = max(premx[ind][i], premx[ind][i + 1]);
    }
    for (lli i = roads[ind].size(); i >= 0; i--){
        sufmx[ind][i] = max(sufmx[ind][i], sufmx[ind][i + 1]);
    }
    sort(all(lmx[ind]));
    reverse(all(lmx[ind]));
    lli i;
    lli ctot = 0;
    for (i = 0; i < roads[ind].size() && i < 3; i++){
        ctot += lmx[ind][i].first;
    }
    if (ctot > mxcnt){
        mxcnt = ctot;
        a = lmx[ind][0].second;
        if (i >= 2){
            b = lmx[ind][1].second;
        }
        else {
            b = ind;
        }
        if (i >= 3){
            c = lmx[ind][2].second;
        }
    }
    for (lli i = 0; i < roads[ind].size(); i++){
        lli cind = roads[ind][i];
        if (cind == parent) continue;
        pair<lli, lli> curr = max(prev, max(premx[ind][i], sufmx[ind][i + 2]));
        curr.first++;
        fndfs(cind, ind, curr);        
    }
    return;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);   
    cin >> n;
    roads.resize(n);
    premx.resize(n);
    sufmx.resize(n);
    lmx.resize(n);
    forp1(n - 1){
        lli a, b;
        cin >> a >> b;
        roads[--a].push_back(--b);
        roads[b].push_back(a);
    }
    dfs(0, -1);
    fndfs(0, -1, {0, 0});
    prnt(mxcnt);
    cout << a + 1 << " " << b + 1 << " ";
    if (c == -1){
        c = 0;
        while (c == a || c == b) c++;
    }
    cout << c + 1 << "\n";
    

}