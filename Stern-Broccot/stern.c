#include <stdio.h>

struct Node{
    int a, b;
}left, mid, right;

int main(void){
    int x,y;
    while (scanf("%d %d",&x,&y)){
        if (x==1 && y==1) break;
        left.a=0; left.b=1;
        mid.a=1; mid.b=1;
        right.a=1; right.b=0;
        while(1){
            long double temp1 = (long double)x/y;
            long double temp2 = (long double)mid.a/mid.b;
            if (temp1 < temp2){
                printf("L");
                right = mid;
                mid.a += left.a;
                mid.b += left.b;
            } else if (temp1 > temp2) {
                printf("R");
                left = mid;
                mid.a += right.a;
                mid.b += right.b;
            } else {               
                printf("\n");
                break;
            }
        }
    }
    return 0;
}