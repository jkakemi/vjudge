#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b; 

    while(getline(cin, a) && getline(cin, b)){
        map<char, int> wordA;
        map<char, int> wordB;
        string new_string = "";
        for(char c : a){
            wordA[c]++;
        }

        for(char c : b){
            wordB[c]++;
        }

        for(auto wa : wordA){
            for(auto wb : wordB){
                if(wa.first == wb.first){
                    int cont = min(wa.second, wb.second);
                    for(int i=0; i<cont; i++){
                        new_string += wa.first;
                    }
                }
            }
        }

        cout << new_string << endl;
    }

    return 0;
}