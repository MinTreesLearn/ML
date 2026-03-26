#include <bits/stdc++.h>
//MACROS
#define rep(i, n) for(int i=0; i<n; i++)
#define rev_rep(i, n) for(int i=n-1; i>=0; i--)
#define index_rep(i, k, n) for(int i=k; i<n; i++)

using namespace std;

//Grafo
vector<vector<int>> derecho;
vector<vector<int>> reves;
vector<int> distancias_desde_final;
vector<bool> visitados;

void crear_grafos(int n){
    derecho.assign(n+1, vector<int>{});
    reves.assign(n+1, vector<int>{});
    distancias_desde_final.assign(n+1, INT_MAX);
    visitados.assign(n+1, false);
}


void agregar_vecino(vector<vector<int>> &grafo, int a, int b){
    grafo[a].push_back(b);
}

void BFS(vector<vector<int>> &grafo, int inicio, int final){
    queue<int> sig_nodo;

    visitados[inicio] = true;
    distancias_desde_final[inicio] = 0;
    sig_nodo.push(inicio);

    int nodo_actual;
    int vecino;

    while(!sig_nodo.empty()){
        nodo_actual = sig_nodo.front();
        sig_nodo.pop();

        for(auto &v : grafo[nodo_actual]){
            if(visitados[v] == false){
                visitados[v] = true;
                sig_nodo.push(v);

                distancias_desde_final[v] = distancias_desde_final[nodo_actual] + 1;
            }
        }
    }

}


int main(){
    //Fast input
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //Input
    int nodos, aristas, a, b;
    cin >> nodos >> aristas;
    crear_grafos(nodos);

    while(aristas--){
        cin >> a >> b;
        agregar_vecino(derecho, a, b);
        agregar_vecino(reves, b, a);
    }

    int k;
    cin >> k;
    vector<int> ruta(k);

    rep(i, k)
        cin >> ruta[i];

    //PROCESAR

    //1. Hacer BFS INVERSO
    BFS(reves, ruta[k-1], ruta[0]);

    //2. Seguir ruta
    int distancia_actual = distancias_desde_final[ruta[0]];
    int nodo_actual, nodo_anterior;
    int minimos = 0;
    int maximos = 0;

    int idx = 0;
    for(idx=1; idx<k; idx++){
        nodo_actual = ruta[idx];
        nodo_anterior = ruta[idx-1];
        
        if(distancia_actual <= distancias_desde_final[nodo_actual]){
            //Ruta peor
            minimos++;
            maximos++;
        }

        else{
            
            //Revisar vecinos
            for(auto &v : derecho[nodo_anterior]){
                if(distancias_desde_final[v] == distancias_desde_final[nodo_actual] && v != nodo_actual){
                    maximos++;
                    break;
                }
            }
        }

        distancia_actual = distancias_desde_final[nodo_actual];
    }

    //Resultado
    cout << minimos << " " << maximos << "\n";

    return 0;
}
	  				 	 	  				 		  			