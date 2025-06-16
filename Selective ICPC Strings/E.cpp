#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> grafo;

bool verificarDoublet(const string& w1, const string& w2){
    if(w1.length() != w2.length()){
        return false;
    }

    int diff = 0;
    for(size_t i=0; i<w1.length(); i++){
        if(w1[i] != w2[i]) diff++;
    }

    if(diff == 1){
        return true;
    }
}

vector<string> bfs(map<string, vector<string>>& adj, const string& start, const string& end) {
    queue<string> q;
    map<string, string> parent;
    map<string, bool> visited; 

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == end) {
            vector<string> path;
            string temp = end;
            while (temp != start) {
                path.push_back(temp);
                temp = parent[temp];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const string& neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr; 
                q.push(neighbor);
            }
        }
    }

    return {}; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string word;
    vector<string> words;
    while(getline(cin, word)){
        if(word.empty()) break;
        words.push_back(word);
    }

    for(size_t i=0; i<words.size(); i++){
        for(size_t j=i+1; j<words.size(); j++){
            if(verificarDoublet(words[i], words[j])){
                grafo[words[i]].push_back(words[j]);
                grafo[words[j]].push_back(words[i]);
            }
        }
    }

    string line; getline(cin, line);

    string start, end;
    bool first_case = true; 

    while(cin >> start >> end){
        if(!first_case){
            cout << "\n"; 
        }
        first_case = false;

        vector<string> path = bfs(grafo, start, end);

        if(path.empty()){
            cout << "No solution.\n";
        }
        else{
            for(const string& p : path){
                cout << p << "\n"; 
            }
        }
    }

    return 0;
}

// regra: doublet, ou seja, uma letra de diferente e mesmo tamanho!
// Logo, criar um grafo e percorrer ele em BFS

// INCOMPLETO
