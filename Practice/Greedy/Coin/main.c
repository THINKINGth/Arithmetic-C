#include <stdio.h>
int Conversion(int x,int *c,int *a,int n);
int main() {
    int x;
    int c[6] = {1,5,10,50,100,500};
    int a[6];
    for(int i = 0; i < 6;i++){
        scanf("%d ",&a[i]);
    }
    scanf("%d",&x);
    printf("%d",Conversion(x,c,a,0));
    return 0;
}
int Conversion(int x,int *c,int *a,int n) {
    if(x == 0)return n;
    for(int i = 5;i >= 0; i--){
        int bn = x - c[i];
            if((bn >= 0) && (a[i] != 0)){
                a[i] = a[i] - 1;
                return Conversion(bn,c,a,++n);
            }
    }
}