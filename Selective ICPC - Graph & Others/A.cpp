#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    while(cin >> n){
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        vector<bool> flag(n, false);
        for(int i=0; i<n-1; i++){
            int absoluto = abs(a[i]-a[i+1]);
            if(absoluto > 0 && absoluto < n){
                flag[absoluto] = true;
            }
        }

        bool achou = true;
        for(int i=1; i<n; i++){
            if(!flag[i]){
                achou = false;
                break;
            }
        }

        if(!achou) cout << "Not jolly\n";
        else cout << "Jolly\n";
    }
    return 0;
}