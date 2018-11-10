#include <stdio.h>
#define N 100
/*
 * Computing The Fibonacci Number
 */
int FibR(int n);
int FibI(int n,int a,int b,int count);
int FibRi(int n,int a[n]);
int main() {
    int n;
    scanf("%d",&n);
    int a[N]= {0};
    printf("%d\n",FibRi(n,a));
    printf("%d\n",FibI(n,1,1,1));
    printf("%d\n",FibR(n));
    return 0;
}
/*
 * Recursion
 */
int FibR(int n){
    if(n == 1)return 1;
    else if(n == 2)return 1;
    return  FibR(n - 1) + FibR(n - 2);
}
/*
 * Iteration
 */
int FibI(int n,int a,int b,int count){
    if(n == count)return b;
    ++count;
    return FibI(n,a+b,a,count);
}
/*
 * Improved iterative
 */
int FibRi(int n,int a[n]){
    if((n == 1 )||(n == 2)){
        a[n - 1] = 1;
        return 1;
    }
    if(a[n - 1] == 0){
        a[n - 1] = FibRi(n - 1,a) + FibRi(n - 2,a);
    }
    return a[n - 1];
}