#include <stdio.h>
#include <stdbool.h>
/*
 *  Question：Full permutation.
 *            Get 0 - n-1 full permutation.
 */

/*  @function: void permutation(int pos,int n,bool used[],int loc[]);
 *  @variable:
 *  pos: Present position
 *  n: N-1 numbers in full permutation.
 *  used[]: Uesd location.
 *  loc[]: Position set.
 */
void permutation(int pos,int n,bool used[],int loc[]);
int main() {
    int n;
    scanf("%d",&n);
    bool used[n+1];
    int loc[n+1];
    permutation(0,n,used,loc);
    return 0;
}
void permutation(int pos,int n,bool used[],int loc[]) {
    if (pos == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", loc[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            loc[pos] = i;
            used[i] = true;
            permutation(pos + 1, n, used, loc);
            used[i] = false;
        }
    }
}