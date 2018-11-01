#include <iostream>
#include <utility>
#define N 100
#include <algorithm>
/*
 * Range of problems
 */
int solve(int n,int res,int *s,int *t,std::pair<int,int>itv[N]);
int main() {
    std::pair<int,int>itv[N];
    int n;
    scanf("%d",&n);
    int s[n],t[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&s[i]);
        itv[i].second = s[i];
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&t[i]);
        itv[i].first = t[i];
    }
    sort(itv,itv+n);
    std::cout<<solve(n,1,s,t,itv);
    return 0;
}
int solve(int n,int res,int *s,int *t,std::pair<int,int>itv[N]){
    for(int i = 0,j = i + 1;j < n;j++){
        if(itv[i].first < itv[j].second){
            res++;
            i = j;
        }
    }
    return res;
}