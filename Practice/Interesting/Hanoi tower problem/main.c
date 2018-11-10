#include <stdio.h>
/*
 * Hanoi tower problem
 */
int TowerofHanoi(int n);
int main() {
    int s;
    scanf("%d",&s);
    printf("%d",TowerofHanoi(s));
    return 0;
}
int TowerofHanoi(int n){
    if(n == 1)return 1;
    return 2 * TowerofHanoi(n - 1)+1;
}
