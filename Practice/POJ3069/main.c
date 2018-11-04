#include <stdio.h>
#include <stdbool.h>
/*
 * Saruman is Army
 * POJ 3069
 */
int solve(int n,int R,int res,int X[n]);
int main() {
    int n,R;
    scanf("%d",&n);
    scanf("%d",&R);
    int X[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&X[i]);
    }
    printf("%d",solve(n,R,0,X));
    return 0;
}
int solve(int n,int R,int res,int X[n]){
    bool flag = false;
    for(int i = 0;i < n;i++){
        int max = X[i] + R;
        flag = false;
        for(int j = i + 1;j < n;j++){
            if(X[j] > max){
                if(flag == true){
                    i = j - 1;
                    flag = false;
                    break;
                }
                if(X[j - 1] + R < X[j]){
                    res++;
                    if(j == (n - 1)){
                        //当该元素不在前一个标记的范围内，且是数组中的最后一个元素时，该元素也需要标记。
                        res++;
                        i = j - 1;
                        break;
                    }
                    i = j - 1;
                    break;
                }
                else{
                    res++;
                    max = X[j - 1] + R;
                    flag = true;
                }
            }
        }
    }
    return res;
}