#include <stdio.h>

int any_odd_one(int x){
    return !!(x & 0xAAAAAAAA);
}

void main(){
    int x=0x4;
    printf("Result: %i",any_odd_one(x));
}