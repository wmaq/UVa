#include <stdio.h>

int main(void){
    char n[100];
    int x;  
    while (scanf("%s", n) == 1){
        if (n[0] == '-')break;
        if (n[0] == '0' && n[1] == 'x') {
            sscanf(n, "%X", &x);
            printf("%d\n", x);
        } else {
            sscanf(n, "%d", &x);
            printf("0x%X\n", x);
        }
    }
    return 0;
}