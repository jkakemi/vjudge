#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> enemy;

int find(int x){ 
    if(parent[x] != x)  
        parent[x] = find(parent[x]);   
    return parent[x]; 
} 
 
int union_sets(int i, int j){ 
    int a = find(i), b = find(j); 
    if(a != b){ 
        parent[b] = a;  
        return a;
    }
    return a;
} 

void setFriends(int u, int v){
    int rootU = find(u);
    int rootV = find(v);

    // 1 5 2
    // posicao 5 tem como root == 0 e 0 == 0, logo, sao inimigos e nao podem ser
    // adicionados como amigos
    if((enemy[rootU] != -1 && enemy[rootU] == rootV) || 
    (enemy[rootV] != -1 && enemy[rootV] == rootU)){
        cout << -1 << endl;
        return;
    }

    // mesmo root e passou pelo enemy, sao amigos
    if(rootU == rootV) return;

    // enemyU = enemy[rootU] = enemy[0];
    // enemyV = enemy[rootV] = enemy[0];
    int enemyU = enemy[rootU];
    int enemyV = enemy[rootV];

    // 
    int root = union_sets(rootU, rootV);

    if(enemyU != -1 && enemyV != -1){
        int newEnemy = union_sets(enemyU, enemyV);
        enemy[root] = newEnemy;
        enemy[newEnemy] = root;
    }
    else if(enemyU != -1){
        enemy[root] = enemyU;
        enemy[enemyU] = root;
    } 
    else if(enemyV != -1){
        enemy[root] = enemyV;
        enemy[enemyV] = root;
    }
}

void setEnemies(int u, int v){
    int rootU = find(u);
    int rootV = find(v);

    if(rootU == rootV){
        cout << -1 << endl;
        return;
    }

    if(enemy[rootU] != -1){
        union_sets(enemy[rootU], rootV);
    }
    else enemy[rootU] = rootV;

    if(enemy[rootV] != -1){
        union_sets(enemy[rootV], rootU);
    }
    else enemy[rootV] = rootU;

    rootU = find(u);
    rootV = find(v);
    enemy[rootU] = find(rootV);
    enemy[rootV] = find(rootU);
}

void areFriends(int u, int v){
    if(find(u) == find(v)){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}

void areEnemies(int u, int v){
    int rootU = find(u);
    int rootV = find(v);

    if((enemy[rootU] != -1 && find(enemy[rootU]) == rootV) ||
        (enemy[rootV] != -1 && find(enemy[rootV]) == rootU)){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n; cin >> n;

    parent.resize(n);
    enemy.assign(n, -1);
    int u, v, op;

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    while(cin >> op >> u >> v && (op != 0 || u != 0 || v != 0)){
        if(op == 1){
            setFriends(u, v);
        }
        else if(op == 2){
            setEnemies(u, v);
        }
        else if(op == 3){
            areFriends(u, v);
        }
        else if(op == 4){
            areEnemies(u, v);
        }
    }
    
    return 0;
}

