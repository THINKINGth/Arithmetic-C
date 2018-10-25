#include <stdio.h>
/*
 *  Newton method for square root
 */
double Newton(double a,double b);
int main() {
   double a = 1 , b;
   scanf("%lf",&b);
   double c = Newton(a,b);
   printf("%f",c);
}
double Newton(double a,double b){
    double c = (a + b/a)/2;
    if(c*c - b <  0.000001)return c;
    return Newton(c,b);
}