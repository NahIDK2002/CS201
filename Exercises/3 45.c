#include <stdio.h>

struct REC{
    char c;
    short d;
    int g;
    float b;
    long e;
    double f;
    int *a;
    char *h;
};

void main(){
    struct REC r;
    printf("Size of REC: %d",sizeof(r));
}