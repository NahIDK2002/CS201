#include <stdio.h>

int lower_one_mask(int n){
    return (2<<(n-1))-1;
}

void main(){
    int n=32;
    printf("Result is: %x",lower_one_mask(n));
}