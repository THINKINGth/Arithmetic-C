#include <stdio.h>
#include <stdbool.h>
/*
 * ZOJ 1002
 */
bool solveR(int N,char a[N][N],int i,int j);
bool solveL(int N,char a[N][N],int i,int j);
int main() {
    int N,res = 0;
    scanf("%d",&N);
    char a[N][N];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(a[i][j] == '.'){
                    solveR(N,a,i,j);
                    solveL(N,a,i,j);
                    res++;
            }
        }
    }
    printf("%d",res);
    return 0;
}
/*
 * Search by row
 */
bool solveR(int N,char a[N][N],int i,int j){
    a[i][j] = 'O';
    int aim = i + 1;
    if((aim >= 0) && (aim < N) && (a[aim][j] == '.')){
        solveR(N,a,aim,j);
    }
}
/*
 * Search by line
 */
bool solveL(int N,char a[N][N],int i,int j){
    a[i][j] = 'O';
    int aim = j + 1;
    if(aim >= 0 && aim < N && a[i][aim] == '.'){
        solveL(N,a,i,aim);
    }
}
