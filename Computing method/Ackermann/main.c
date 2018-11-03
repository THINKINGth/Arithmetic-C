#include <stdio.h>
/*
 * Ackermann function
 * x == 0: 2 * y;
 * x == 1; 2^y; (^ : power)
 * x == 2; 2^2^2...y...2;
 */
int Ackermann(int x,int y);
int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",Ackermann(x,y));
    return 0;
}
int Ackermann(int x,int y){
    if(y == 0)return 0;
    else if(x == 0)return 2 * y;
    else if(y == 1)return 2;
    else{
         Ackermann(x-1,Ackermann(x,y-1));
    }
}