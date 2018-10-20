#include <stdio.h>
void solve_1();
int main() {
    solve_1();
}
/*  Question: Hundred yuan hundred chicken problem.
 *            Use 100 yuan to buy 100 chickens.
 *  Condition: cock:5 yuan,hen:3 yuan,chickens:1/3 yuan;
 */
void solve_1(){
    int x = 5,y = 3,z = 1/3;
    for(int i = 0;i <= 100;i++){
        for(int j = 0;j <= 100 - i; j++){
            if((100-i-j)%3 == 0){
                if(((x * i) + (y * j) + ((100-i-j)/3)) == 100)
                    printf("%d %d %d\n",i,j,(100-i-j));
            }
        }
    }
}