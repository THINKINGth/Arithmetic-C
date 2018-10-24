#include <stdio.h>
/*
 * Computing The Fibonacci Number
 */
int FibR(int n);
int FibI(int n,int a,int b,int count);
//int FibRi(int n,int a[n]);
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
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
