#include <stdio.h>
#include <stdbool.h>
/*
 *  Best Cow Line
 */
int str(int i,int j,int r,int n,char s[n],char t[n]);
bool Isfirst(int i,int j,int n,char s[n],char t[n]);
int main() {
    int n;
    scanf("%d\n",&n);
    char s[n],t[n];
    for(int i = 0;i < n;i++){
        scanf("%c",&s[i]);
    }
    str(0,n-1,0,n,s,t);
    for(int i = 0;i < n;i++){
        printf("%c",t[i]);
    }
    return 0;
}
int str(int i,int j,int r,int n,char s[n],char t[n]){
    while(i <= j){
        if(s[i] < s[j]){
            t[r] = s[i];
            r++;i++;
        }
        else if(s[i] == s[j]){
            if(Isfirst(i+1,j-1,n,s,t)){
                t[r] = s[i];
                r++;i++;
            }
            else{
                t[r] = s[j];
                r++;j--;
            }
        }
        else{
            t[r] = s[j];
            r++;j--;
        }
    }
}
bool Isfirst(int i,int j,int n,char s[n],char t[n]){
    while(i <= j){
        if(s[i] < s[j])return true;
        else if(s[i] == s[j])Isfirst(i + 1,j - 1,n,s,t);
        else return false;
    }
}