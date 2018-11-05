#include <stdio.h>
/*
 * Fence Repair
 * POJ 3253
 */
int solve(int S,int N,int SUM,int USE,int a[N]);
int* sort(int n ,int *a);
int main() {
    int SUM = 0,N = 0;
    scanf("%d",&N);
    int a[N];
    for(int i = 0;i < N;i++){
        scanf("%d",&a[i]);
        SUM += a[i];
    }
    sort(N,a);
    printf("%d",solve(0,N,SUM,0,a));
    return 0;
}
int solve(int S,int N,int SUM,int USE,int a[N]){
    if((N - S) == 1){
        return USE;
    }
    else{
        int n = S,FIRST = 0;
        for(int i = S;i < N;i++,n++){
            FIRST = FIRST + a[i];
            SUM = SUM - a[i];
            if((i + 1 < N) && ((FIRST + a[i + 1]) > (SUM - a[i + 1]))){
                if((FIRST + a[i + 1]) - (SUM - a[i + 1]) >SUM - FIRST){
                    USE = USE + FIRST + SUM;
                    USE = solve(S,n+1,FIRST,USE,a);
                    solve(n+1,N,SUM,USE,a);
                    break;
                }
            }
        }

    }
}

int* sort(int n ,int *a){
    for(int i = 1,j;i < n;i++){
        int key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return a;
}