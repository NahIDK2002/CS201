#include <stdio.h>

void print_binary(int number)
{
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}

int testOptionA(int x){
    return !!x;
}

int testOptionB(int x){
    return !!(~x);
}

int testOptionC(int x){
    return !!(x & 0xFF);
}

int testOptionD(int x){
    return !!(~x && (0xFF<<24));
}

int testOptionDFIX(int x){
    return !!(~x && (0xFF<<(sizeof(int)<<3)));
}

void main(){
    int x=0b100;

    printf("Test option A: %i\n",testOptionA(x));
    printf("Test option B: %i\n",testOptionB(x));
    printf("Test option C: %i\n",testOptionC(x));
    printf("Test option D: %i\n",testOptionDFIX(x));
}