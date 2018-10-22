#include <stdio.h>
/* Deep first search.
 * @Question: Find the largest puddle area.
 *            'w' is puddle area, '.' is land.
 * POJ 2386
 */
void dfs(int i,int j,int N,int M,int a[N][M]);
int main() {
    int res = 0,N,M;
    scanf("%d",&N);
    scanf("%d",&M);
    int a[M][N];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            scanf("%c ",&a[i][j]);
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(a[i][j] == 'w') {
                dfs(i, j, N, M, a);
                res++;
            }
        }
    }
    printf("%d",res);
    return 0;
}
void dfs(int i,int j,int N,int M,int a[N][M]){
    a[i][j] = '.';
    for(int x = -1;x <= 1;x++){
        for(int y = -1;y <= 1;y++){
            if(i >= 0 && i <= N && j >= 0 &&j <= M && a[i+x][j+y] == 'w')
                dfs(i+x,j+y,N,M,a);
        }
    }
}