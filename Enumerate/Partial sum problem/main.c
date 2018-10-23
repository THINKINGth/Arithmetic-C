#include <stdio.h>
#include <stdbool.h>
/*
 * Partial sum problem
 * Question：Given integer a1,a2,--an,Determine whether a number of them can be selected so that their sum is exactly k.
 * 1 <= n <= 20;
 * -10^8 <= ai <= 10^8
 * -10^8 <= k <= 10^8
 */

bool dfs(int i,int n,int sum,int k,int a[n]);
int b[];
int main() {
    int n,k,sum = 0;
    scanf("%d",&n);
    int a[n];
    b[n];
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    if(dfs(0,n,sum,k,a)){
        puts("Yes");
    }
    else{
        puts("No");
    }
    for(int i = 0;i < n;i++){
        if(b[i])
            printf("%d ",b[i]);
    }
    return 0;
}
/*
 *  Use depth-first search to solve the selection problem;
 */
bool dfs(int i,int n,int sum,int k,int a[n]){
    if(i == n)return sum == k;
    if(dfs(i + 1,n,sum,k,a))return true;
    if(dfs(i + 1,n,sum + a[i],k,a))
    {
        b[i] = a[i];
        return true;
    }
    return false;
}