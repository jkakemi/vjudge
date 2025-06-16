#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& g){
    int V = g.size();

    for(int k=1; k<V; k++){
        for(int i=1; i<V; i++){
            for(int j=1; j<V; j++){
                if(g[i][k] != INF && g[k][j] != INF){
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int cases; cin >> cases;
    cin.ignore();
    cin.ignore();
    while(cases--){
        // string line; getline(cin, line);    

        int qExistentes, cruzamentos; 
        cin >> qExistentes >> cruzamentos;

        vector<int> quarteis(qExistentes);
        for(int i=0; i<qExistentes; i++) cin >> quarteis[i];

        vector<vector<int>> grafo(cruzamentos+1, vector<int>(cruzamentos+1, INF));

        for(int i=1; i<=cruzamentos; i++){
            grafo[i][i] = 0;   
        }

        cin.ignore();
        string line;
        while(getline(cin, line) && !line.empty()){
            stringstream ss(line);
            int u, v, w; ss >> u >> v >> w;
            grafo[u][v] = w;
            grafo[v][u] = w;
        }
        
        // for(int i=0; i<cruzamentos; i++){
        //     int u, v, w; cin >> u >> v >> w;
        //     grafo[u][v] = w;
        //     grafo[v][u] = w;
        // }

        floydWarshall(grafo);

        int melhorPosicao = -1;
        int distMin = INF;

        for(int i=1; i<=cruzamentos; i++){
            int distAtual = 0;

            for(int j=1; j<=cruzamentos; j++){
                int candidato = grafo[j][i];

                for(int q : quarteis){
                    candidato = min(candidato, grafo[j][q]);
                }

                distAtual = max(distAtual, candidato);
            }

            if(distAtual < distMin){
                distMin = distAtual;
                melhorPosicao = i;
            }
        }

        cout << melhorPosicao << endl;
        if(cases > 0){
            cout << endl;
        }
        //grafo desenhado
        // for(int i=1; i<grafo.size(); i++){
        //     for(int j=1; j<grafo.size(); j++){
        //         cout << grafo[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}