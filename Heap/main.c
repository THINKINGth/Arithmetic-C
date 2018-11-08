#include <stdio.h>
#define MAX 100
/*
 * Heap
 */
void push(int x);
int pop();
int heap[MAX],sz = 0;
int main() {
    return 0;
}
void push(int x){
    int i = sz++;
    while (i > 0){
        int p = (i - 1)/2;
        if(heap[p] <= x)break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}
int pop(){
    int min = heap[0];
    int x = heap[--sz];
    int i = 0;
    while(i * 2 + 1 <sz){
        int left = i * 2 +1,right = i * 2 + 2;
        if(right < sz && heap[right] < heap[left]){
            left = right;
        }
        if(heap[left] > x)break;
        heap[i] = heap[left];
        i = left;
    }
    heap[i] = x;
    return min;
}