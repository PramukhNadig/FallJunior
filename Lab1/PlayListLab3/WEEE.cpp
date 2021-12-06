#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int k = 0;
    int n = 3;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j+=i){
            cout << ++k << endl;
          }
    }
    return 0;
}