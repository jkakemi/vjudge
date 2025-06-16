#include <bits/stdc++.h>

using namespace std;

int n;

int dijkstra(vector<vector<pair<int, int>>>& grafo, int n, int s, int t){
    priority_queue<pair<int, int>> fila;
    vector<int> dist(n+1, 0);

    dist[s] = INT_MAX;
    fila.push({dist[s], s});

    while(!fila.empty()){
        int u = fila.top().second;
        int g_u = fila.top().first;
        fila.pop();

        if(g_u < dist[u]) continue;

        for(auto x : grafo[u]){
            int v = x.first;
            int peso = x.second;

            int gargalo = min(dist[u], peso);

            if(gargalo > dist[v]){
                dist[v] = gargalo;
                fila.push({dist[v], v});
            }

            // if(dist[v] > dist[u]+peso){
            //     dist[v] = dist[u] + peso;
            //     fila.push({dist[v], v});
            // }
        }
    }

    return dist[t];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cont=0;
    int r;
    while(cin >> n >> r && (n != 0 || r != 0)){
        vector<vector<pair<int, int>>> grafo(n+1, vector<pair<int, int>>());
        for(int i=0; i<r; i++){
            int u, v, w;
            cin >> u >> v >> w;
            
            grafo[u].push_back({v, w-1});
            grafo[v].push_back({u, w-1});
        }

        int s, d, t; cin >> s >> d >> t;

        int maxCapacity = dijkstra(grafo, n, s, d);

        int min = (t+maxCapacity-1)/maxCapacity;
        cout << "Scenario #" <<  cont+1 << endl;
        cout << "Minimum Number of Trips = " << min << endl;
        cout << endl;
        cont++;
    }
    return 0;
}