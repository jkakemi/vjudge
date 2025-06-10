#include <bits/stdc++.h>

using namespace std;

// WA - arrumar, logica errada

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    //string alfabetoMaluco = "ap bl co dk em fi gj hn iu jh kb ly mg nv ot pf qc rr sd tx ue vs wz xa yq zw";

    map<char, char> cripto = {{'a', 'p'}, {'b', 'l'}, {'c', 'o'}, {'d', 'k'}, {'e', 'm'}, {'f', 'i'}, {'g', 'j'}, {'h', 'n'},
    {'i', 'u'}, {'j', 'h'}, {'k', 'b'}, {'l', 'y'}, {'m', 'g'}, {'n', 'v'}, {'o', 't'}, {'p','f'}, {'q', 'c'}, {'r', 'r'},
    {'s', 'd'}, {'t', 'x'}, {'u', 'e'}, {'v', 's'}, {'w', 'z'}, {'x', 'a'}, {'y', 'q'}, {'z', 'w'}};

    int n; cin >> n;
    cin.ignore();
    string line; getline(cin, line);

    while(n--){
        string sentence; getline(cin, sentence);
        // vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
        string descripto = "";
        for(size_t i=0; i<sentence.size(); i++){
            if(sentence[i] == ' '){
                //cout << "ENTROU " << sentence[i] << " POS " << i << endl;
                descripto += ' '; 
            }
            else{
                for(auto c : cripto){
                    if(sentence[i] == c.second){
                        descripto += c.first;
                        break;
                    }
                }
            }
        }

        cout << descripto << endl;
    }

    return 0;
}