#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string letters = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    string s;

    while(getline(cin, s)){
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<48; j++){
                if(s[i] == letters[j]){
                    cout << letters[j-1];
                    break;
                }
                if(s[i] == ' '){
                    cout << " ";
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}