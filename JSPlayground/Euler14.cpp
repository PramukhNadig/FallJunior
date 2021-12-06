#include <bits/stdc++.h>


using namespace std;

int collatz(int i, int* array){
    cout << "hi !";

    if(array[i] != -1){
        return array[i];
    }else{
        if(i%2==0){
            return 1 + collatz(i/2, array);
        }else{
            return 1 + collatz((3*i)+1, array);
        }
    }
    return 0;
}
int main(){
    cout << "hi !";
    cout << endl;

    int sequence[1000000] = {-1}; 
    sequence[1] = 0; 
    for(int i = 0; i < 1000000; i++){
        sequence[i] = collatz(i, sequence);
    }
    int max = 0;
    int index = 0;
    for(int i = 0; i < 1000000; i++){
        if(sequence[i] > max){
            max = sequence[i];
            index = i;
        }
    }
    cout << max << " : " << index;

    return 0;
}