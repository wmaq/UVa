#include <stdio.h>

int main(void){
    int N,n,k;
    scanf("%d", &N);
    while(N--){
        scanf("%u %u", &n, &k);
        printf("%u\n", (k^(k>>1)) );
    }
    return 0;
}