#include <stdio.h>
/*
 * Fence Repair
 * POJ 3253
 */
int solveONE(int S,int N,int SUM,int USE,int a[N]);
int solveTWO(int N,int a[N]);
int* sort(int n ,int *a);
void swaps(int *x,int *y);
int main() {
    int SUM = 0,N = 0;
    scanf("%d",&N);
    int a[N];
    for(int i = 0;i < N;i++){
        scanf("%d",&a[i]);
        SUM += a[i];
    }
    sort(N,a);
    printf("%d\n",solveONE(0,N,SUM,0,a));
    printf("%d",solveTWO(N,a));
    return 0;
}
int solveONE(int S,int N,int SUM,int USE,int a[N]){
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
                    USE = solveONE(S,n+1,FIRST,USE,a);
                    solveONE(n+1,N,SUM,USE,a);
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
void swaps(int *x,int *y){
    int *a = x,*b = y,c;
    c = *a;*a = *b;
    *b = c;
}
int solveTWO(int N,int a[N]){
    int ans = 0;
    while(N > 1){
        int MIN1 = 0,MIN2 = 1;
        if(a[MIN1] > a[MIN2]){
            swaps(&MIN1,&MIN2);
        }
        for(int i = 2;i < N;i++){
            if(a[i] < a[MIN1]){
                MIN2 = MIN1;
                MIN1 = i;
            }
            else if(a[i] < a[MIN2]){

                MIN2 = i;
            }
        }
        int Min = a[MIN1] + a[MIN2];
        ans += Min;
        if(MIN1 == N - 1){
            swaps(&MIN1,&MIN2);
        }
        a[MIN1] = Min;
        a[MIN2] = a[N-1];
        MIN2 = N - 1;
        N--;
    }
    return ans;
}