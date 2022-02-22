#include <stdio.h>

int multipleBy17(int x){
    return (x<<4)+x;        // <=> 16x+x
}

int multipleByMinus7(int x){
    return -(x<<3)+x;       // <=> -8x+x;
}

int multipleBy60(int x){
    return (x<<6)-(x<<2);   // <=> 64x-4x;
}

int multipleByMinus112(int x){
    return -(x<<7)+(x<<4);  // <=> -128x + 16x;
}

void main(){
    int x=2;
    printf("17x   = %i\n",multipleBy17(x));
    printf("-7x   = %i\n",multipleByMinus7(x));
    printf("60x   = %i\n",multipleBy60(x));
    printf("-112x = %i\n",multipleByMinus112(x));
}