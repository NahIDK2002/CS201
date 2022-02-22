#include <stdio.h>

void print_binary(unsigned number)
{
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}

unsigned bitPatternTypeA(int k){
    int w=sizeof(int)*8;
    unsigned ans=1<<(w-k);
    ans--;
    ans<<=k;
    return ans;
}

unsigned bitPatternTypeA_FIX(int k){
    return ~((1<<k)-1);
}

unsigned bitPatternTypeB(int k, int j){
    unsigned ans = 1<<(k);
    ans--;
    ans<<=j;
    return ans;
}

unsigned bitPatternTypeB_FIX(int k, int j){
    return ((1<<k)-1) << j;
}

void main(){
    int k=30,j=2;
    unsigned typeA=bitPatternTypeA(k);
    unsigned typeB=bitPatternTypeB(k,j);
    printf("Result of bit pattern type A: %hu or ",typeA);
    print_binary(typeA);
    printf("\n");
    printf("Result of bit pattern type B: %hu or ",typeB);
    print_binary(typeB);
    printf("\n");
}