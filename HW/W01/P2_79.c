#include <stdio.h>

int mul3div4(int x){
    return x-(x>>2);
}

int mul3div4FIX(int x){
    int mul3 = x+(x<<1);
    int mul3_mask = mul3 >> ((sizeof(int)<<3)-1);
    int bias = mul3_mask & 3;
    return (mul3+bias)>>2;
}

void main(){
    int x=3;
    printf("Result is: %i",mul3div4(x));
}