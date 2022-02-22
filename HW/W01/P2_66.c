#include <stdio.h>

void print_binary(unsigned number)
{
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}

int leftmost_one(unsigned x){
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;

    return (x >> 1) + ( x && 1);
}

void main(){
    unsigned x= 0b10000001;
    printf("Result is: %x", leftmost_one(x));
}