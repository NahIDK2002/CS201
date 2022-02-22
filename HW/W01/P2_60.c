#include <stdio.h>
#include <math.h>

unsigned replace_byte (unsigned x, int i, unsigned char b){
    unsigned tmp1=pow(2,33)-pow(2,(i+1)*8); //get bits in front
    unsigned tmp2=pow(2,i*8)-1; // get bits in back

    unsigned ans=x&tmp1;
    ans+=(b<<(i*8));    // fill the hole
    ans+=x&tmp2;
    return ans;
}

unsigned replace_byteFIX(unsigned x, int i, unsigned char b){
    int ix8 = i << 3;
    unsigned mask = 0xFF << ix8;
    return (x &~mask) | (b << ix8);
}

void main(){
    unsigned x=0x12345678;
    int i=0;
    unsigned char b=0xAB;

    unsigned ans1=replace_byte(x,i,b);
    unsigned ans2=replace_byteFIX(x,i,b);

    printf("Result is: %i or %X\n",ans1,ans1);
    printf("Result is: %i or %X\n",ans2,ans2);
}