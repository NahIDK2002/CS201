#include <stdio.h>
#include <math.h>

#define INT_MAX 2147483647 
#define INT_MIN -2147483647 - 1 

int saturating_add(int x, int y){
    int sum=x+y;
    int wm1 = (sizeof(int)<<3)-1;
    int xneg_mask=(x >> wm1);   //check x is pos or neg
    int yneg_mask=(y >> wm1);   // check y is pos or neg
    int sneg_mask = (sum>>wm1); // check sum is pos or neg

    int pos_over_mask = ~xneg_mask & ~yneg_mask & sneg_mask;    //check if overflow int in pos side
    int neg_over_mask = xneg_mask & yneg_mask & ~sneg_mask;     //check if overflow int in neg side

    int over_mask = pos_over_mask | neg_over_mask;  // check if overflow
                  //not overflow      if overflow in pos side      if overlow in neg side   
    int result = (~over_mask & sum) | (pos_over_mask & INT_MAX) | (neg_over_mask & INT_MIN);

    return result;
}

void main(){
    int x=1;
    int y=2147483647;
    printf("Result: %i",saturating_add(x,y));
}