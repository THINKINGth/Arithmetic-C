#include <stdio.h>
#define NUM 20
int int_read(char str[], int size);
int count(char *str, int start);
void turn(char * str, int start, int end);
void Turnstr(char *str, int length);
int strlen(char *str);
int main() {
    char str[NUM + 1];
    int_read(str, NUM);
    Turnstr(str, strlen(str) - 1);
    printf("%s", str);
    return 0;
}
int count(char* str, int start){
    while((str[start] != ' ') && (str[start] != '\0')){
        start++;
    }
    return start;
}

void turn(char *str, int start, int end){
    int ch = str[start];
    while(start < end){
        str[start++] = str[end];
        str[end--] = ch;
        ch = str[start];
    }
}

int int_read(char str[], int size){
    int i = 0; int ch = 0;
    while((i < size) && (ch = getchar()) != '\n'){
        str[i++] = ch;
    }
    str[i] = '\0';
}

void Turnstr(char *str, int length){
    int start = 0;
    int end = count(str, start);
    while ((start == 0) ||(str[start - 1] != '\0')){
        turn(str, start, end - 1);
        start = end + 1;
        end = count(str, start);
    }
    turn(str, 0, length);
}

int strlen(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i += 1;
    }
    return i;
}