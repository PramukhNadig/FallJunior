/**If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

**/
#include <stdio.h>
#include <iostream>

using namespace std;

bool mulThreeFive(int n){
    return n % 3 == 0 || n % 5 == 0;
}

int main() {
    int sum = 0;
    for(int i = 0; i < 1000; i++){
        if(mulThreeFive(i)){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}