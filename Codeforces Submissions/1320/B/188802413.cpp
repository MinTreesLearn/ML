#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grafo;
vector<vector<int>> grafoOr;
vector<int> dis;
int inf = 2147483640;

void start(int n){
    for(int i = 0; i<n;i++){
        grafo.push_back({});
        grafoOr.push_back({});
        dis.push_back(inf);
    }
}

void conect(int a, int b){
    grafo[b].push_back(a);
    grafoOr[a].push_back(b);
}

pair<int,int> count(vector<int> caminoP){
    int min=0, max=0, i=0;
    int nodAc = caminoP[i];
    int nodSg = caminoP[i+1];
    int disAc;
    int disSg;
    while (nodSg!=caminoP[caminoP.size()-1])
    {
        disAc = dis[nodAc];
        disSg = dis[nodSg];
        if(disAc<=disSg){
            min++;
            max++;
        }
        else {
            int vecMin=-1;
            bool igual = false;
            for(int vec : grafoOr[nodAc]) {
                vecMin = (vecMin == -1 ? dis[vec] : std::min(vecMin, dis[vec]));
                if(dis[vec] == disSg && nodSg != vec) igual=true;
            }
            if(vecMin < disSg){
                min++;
                max++;
            }
            else if(igual){
                max++;
            }
        }
        i++;
        nodAc=nodSg;
        nodSg=caminoP[i+1];
    }
    return make_pair(min,max);
}

void dijkstra(int nodo){
    dis[nodo] = 0;
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> next;
    next.push(make_pair(0,nodo));
    while(!next.empty()){
        int act = next.top().second;
        int actDis = next.top().first;
        next.pop();
        if(actDis <= dis[act]){
            for(int i = 0;i<grafo[act].size();i++){
                int ves = grafo[act][i];
                int vesDis = 1;
                if(dis[ves] > dis[act] + 1){
                    dis[ves] = dis[act]+1;
                    next.push(make_pair(dis[ves],ves));
                }
            }
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    start(n);
    int u,v;
    for(int i = 0; i<m; i++){
        cin >> u >> v;
        conect(u-1,v-1);
    }
    int k;
    cin >> k;
    int t;
    vector<int> caminoP;
    for(int i =0; i<k; i++){
        cin >> t;
        caminoP.push_back(t-1);
    }
    dijkstra(caminoP[caminoP.size()-1]);
    pair<int,int> res =count(caminoP);
    cout << res.first << ' ' << res.second << '\n';

    return 0;
}
 		 	 	  	  	  		  			