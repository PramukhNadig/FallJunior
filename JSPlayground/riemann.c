#include <stdio.h>
#include <math.h>

float riemann(int n){

    double total = 5.5;
    double sum = 0.0f;
    double thing = total / n;
    double thing1 = thing;
    thing = thing/2;
    thing-=.5;

    for(int i = 0; i < n; i++){

        sum += ((2.5*pow(thing, 3))-(15.5*pow(thing, 2)) + (20*thing)+ 15)*thing1;
        thing += thing1;
    }
    printf("%lf", sum);
    return sum;
}
int main(){
    riemann(500);
    return 0;
}