#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string a, b;

    while(cin >> a >> b && (a != "0" || b != "0")){
        int cont=0;
        int carry=0;
        int isCarry=0;

        int lenA = a.length()-1;
        int lenB = b.length()-1;

        while(lenA >= 0 || lenB >= 0){
            int da=0, db=0;
            if(lenA >= 0) da = a[lenA]-'0';
            if(lenB >= 0) db = b[lenB]-'0';

            isCarry = da+db+carry;
            carry = 0;
            if(isCarry >= 10){
                cont++;
                carry = 1;
            }
            lenA--;
            lenB--;
        }

        if(cont == 0) cout << "No carry operation.\n";
        else if(cont == 1) cout << "1 carry operation.\n";
        else cout << cont << " carry operations.\n";
    }

    return 0;
}