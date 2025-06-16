#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    while(cin >> n){
        int mod = n;
        int number = 1%n;
        int cont = 1;
        while(number!=0){
            number = (number*10+1)%mod;
            cont++;
        }

        cout << cont << endl;
    }
    
    return 0;
}