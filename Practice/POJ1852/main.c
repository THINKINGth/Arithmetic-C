#include <stdio.h>
void solve(int L,int n,int a[n]);
int max(int x,int y);
int min(int x,int y);
int main() {
    int L,n;
    scanf("%d",&L);
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    solve(L,n,a);
    return 0;
}
//POJ NO.1852
void solve(int L,int n,int a[n]){
    int t_min = 0,t_max = 0;
    for(int i = 0;i < n;i++){
        t_min = max(t_min,min(a[i],L-a[i]));
        t_max = max(t_max,max(a[i],L-a[i]));
    }
    printf("min = %d\nmax = %d",t_min,t_max);
}
// maximum value
int max(int x,int y){
    if(x > y)
        return x;
    return y;
}
// Least value
int min(int x,int y){
    if(x < y)
        return x;
    return y;
}