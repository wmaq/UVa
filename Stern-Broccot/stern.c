#include <stdio.h>

struct Node{
    int M, D;
}left, mid, right;

int main(void){
    int m,n;
    while (scanf("%d %d",&m,&n)){
        if (m==1 && n==1) break;
        while (1){
            long double temp1 = (long double)m/n
            long double temp2 = (long double)mid.M/mid.D;
            if (temp1 < temp2){
                printf("L");
                right = mid;
                mid.M += left.M;
                mid.D += left.D;
            } else if (temp1 > temp2) {
                printf("R");
                left = mid;
                mid.M += right.M;
                mid.D += right.D;
            } else {               
                printf("\n");
                break;
            }
        }
    }
    return 0;
}