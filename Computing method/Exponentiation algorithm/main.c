#include <stdio.h>
#include <stdbool.h>
/*
 * Exponentiation algorithm
 */
int Exponentiation(int x,int n);
int Simple(int x,int n);
bool number(int n);
int main() {
    int x,n;
    scanf("%d",&x);
    scanf("%d",&n);
    printf("%d\n",Exponentiation(x,n));
    printf("%d",Simple(x,n));
    return 0;
}
bool number(int n){
    return n % 2 == 0?1:0;
}
int Exponentiation(int x,int n){
    if(n == 0)return 1;
    else if(number(n)){
        return Exponentiation(x,n/2)*Exponentiation(x,n/2);
    }
    else{
        return x * Exponentiation(x,n - 1);
    }
}
int Simple(int x,int n){
    if(n == 0)return 1;
    return Simple(x,n - 1) * x;
}