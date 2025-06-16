#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int cont=0;
    int n;
    while(cin >> n && n != 0){
        vector<string> judge;
        vector<string> answer;
        cin.ignore();
        for(int i=0; i<n; i++){
            string j; getline(cin, j);
            judge.push_back(j);
        }

        int m; cin >> m;
        cin.ignore();

        for(int i=0; i<m; i++){
            string a; getline(cin, a);
            answer.push_back(a);
        }

        bool flag = true;
        if(n != m){
            flag = false;
        }
        else{
            for(int i=0; i<n; i++){
                if(judge[i] != answer[i]){
                    flag = false;
                    break;
                }
            }

        }

        string judgeDigit = "";
        string answerDigit = "";
        cout << "Run #" << cont+1 << ": ";
        cont++;
        if(flag){
            cout << "Accepted\n";
        }
        else{
            // PE
            for(const string& line : judge){
                for(char c : line){
                    if(isdigit(c)){
                        judgeDigit += c;
                    }
                }
            }
            for(const string& line : answer){
                for(char c : line){
                    if(isdigit(c)){
                        answerDigit += c;
                    }
                }
            }

            if(answerDigit != judgeDigit){
                cout << "Wrong Answer\n";
            }
            else{
                cout << "Presentation Error\n";
            }

            // cout << "JUIZ " << judgeDigit << endl;
            // cout << "RESP " << answerDigit << endl;
        }

    }

    return 0;
}