#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int cases; cin >> cases;
    
    while(cases--){
        long long n; cin >> n;
        long long cont=0;
        //cout << after+n << endl;
        string reverseAdd = to_string(n);
        reverse(reverseAdd.begin(), reverseAdd.end());

        long long after = stoll(reverseAdd);
        long long sum=0;
        while(after != n){
            sum = n+after;

            reverseAdd = to_string(sum);
            reverse(reverseAdd.begin(), reverseAdd.end());

            after = stoll(reverseAdd);
            n = sum;
            cont++;
        }

        cout << cont << " " << after << endl;
    }

    return 0;
}