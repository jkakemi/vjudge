#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string word;
    vector<string> words;
    while(getline(cin, word) && word != "\n"){
        words.push_back(word);
    }



    return 0;
}

// regra: doublet, ou seja, uma letra de diferente e mesmo tamanho!
// Logo, criar um grafo e percorrer ele em BFS