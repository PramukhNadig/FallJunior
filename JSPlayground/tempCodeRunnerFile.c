#include <stdio.h>
#include <math.h>

float findDistance(){
    int x[] = {0.0, 0.4140, 1.4949, 5.0014, 6.5163, 3.9303, 8.4813, 2.6505};
    int y[] = {0.0, 3.9862, 6.1488, 1.047, 4.6102, 1.4057, 5.0371, 4.1196};
    int n = 8;
    float currentMax = 0.00;
    float currentMin = 0.00;
    float a = 0.00;
    float b = 0.00;
    float c = 0.00;
    float d = 0.00;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int l = (x[i]-x[j])*(x[i]-x[j]) +(y[i]-y[j])*(y[i]-y[j]);
            if(l > currentMax){
                a = x[i];
                b = x[j];
                c = y[i];
                d = y[j];
                currentMax = l;
            }else if(l < currentMin){
                currentMin = l;
            }
        }
    }
    return b;
}

int main(int argc, char argv[]){
    printf("%f", findDistance());
    return 0; //
}