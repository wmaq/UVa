#include <stdio.h>
#include <stdlib.h>

char arr[1<<14];
int check(int l, int s, int r){
    if(l == r) return 0;
    int p = 1, ll, lr, rl, rr;
    int pos = atoi ( &arr[l] );
    ll = l;
    while( arr[ll] != '(' ) ll++;
    lr = ll+1;
    while( p ){
        if( arr[lr] == '(' ) p++;
        else if( arr[lr] == ')' ) p--;
        lr++;
    }
    rl = lr, rr = r;
    if( s == pos && (ll+1)==(lr-1) && (rl+1)==(rr-1)) return 1;
    else return (check(ll+1, s-pos, lr-1)||check(rl+1, s-pos, rr-1));
    return 0;
}
int main(void){
    int i, sum, p;
    char c;
    while( scanf("%d", &sum) ){
        scanf("%c", %c);
        i = 0, p = 1;
        arr[i++] = c;
        while( p ){
            scanf("%c", &c);
            arr[i++] = c;
            if(c == '(') p++;
            else if(c == ')') p--;
        }
        if(i == 2) printf("no\n");
        else if(check(sum, 1, i-1) != 0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}