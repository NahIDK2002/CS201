#include <stdio.h>

void main(){
    int x=0x89ABCDEF;
    int y=0x76543210;

    int ans=y&4294967040; // = y&(2^32-2^8);
    ans+=(x&255);         // = x&(2^8-1);
    //ans = (x&0xFF) | (y&~0xFF);
    printf("The result of 0x765432EF: %i", ans);
}