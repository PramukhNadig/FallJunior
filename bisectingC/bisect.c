#include <stdio.h>
#include <math.h>

float f(float x) {
    return 5.3+2.9*x*x-3.1*x*x*x;
}

int main(){
    float a = -10.00;
    float b = 10.00;
    float tolerance = .00001;
    float l;
    if(a < b){
        float c = a;
        a =b;
        b = c;
    }
    while(a > b) {
        l = f(a/2+b/2);

        if(fabs(f(a/2+b/2)) < tolerance){
                printf("%2.6f, %2.6f\n", (f(a/2+b/2)), a/2+b/2);

            break;
        }
        if((f(a) * f(b)) > 0){
            return 0;
        }

        if(f(a/2+b/2) > 0){
            a = a/2+b/2;
        }else{
            b = a/2+b/2;
        }

    }
    printf("%2.9f, %2.6f", l, a/2+b/2);
    return 0;
}