#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

vector< vector< int > > lista_ad;
vector < vector< int >> lista_ad2;
vector< int > distancias;
vector<bool> visitados;

void bfs(int inicio){
  queue <int> cola;

  visitados[inicio] = true;
  cola.push(inicio);
  distancias[inicio] = 0;

  while(!cola.empty()){
    int actual = cola.front();
    cola.pop();
    for(int i = 0; i < lista_ad[actual].size(); i++){
        if(visitados[lista_ad[actual][i]] == false){
            visitados[lista_ad[actual][i]] = true;
            cola.push(lista_ad[actual][i]);
            distancias[lista_ad[actual][i]] = distancias[actual] + 1;
        }
    }
  }
}

void addEdge(int a, int b){
    lista_ad[b].push_back(a);
    lista_ad2[a].push_back(b);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    lista_ad.assign(n, vector<int>(0));
    lista_ad2.assign(n, vector<int>(0));
    visitados.assign(n, 0);
    distancias.assign(n, -1);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        addEdge(a, b);
    } 
    int k, rbmin = 0, rbmax=0;
    cin >> k;
    vector<int> camino(k);
    rep(i, k) cin >> camino[i];
    rep(i, k) camino[i]--;

    bfs(camino[k-1]);

    //rep(i, n) cerr << distancias[i] << endl;

    rep(i, k-1){
        int p = camino[i], l = camino[i+1];

        if(distancias[l] >= distancias[p]){
            rbmin++; rbmax++;
        } else {
            int cnt=0;
            rep(j, lista_ad2[p].size()){
                if(distancias[lista_ad2[p][j]] == distancias[l]) cnt++;
                //cerr << cnt << ' ' << lista_ad2[p][j] << ' ' << p << endl;
                if(cnt == 2){
                    rbmax++;
                    break;
                }
            }
        }

    }

    cout << rbmin << ' ' << rbmax << endl;
    return 0;
}
				     		     			  	   	 				