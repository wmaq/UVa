#include <stdio.h>

int main(void){
    int arr[10005] = {0};
    int l, r, h, i, cityLen=0;
    while( scanf("%d %d %d", &l, &h, &r)!=EOF ){
        for(i = l; i < r; i++){
            if(h > arr[i]) arr[i]=h;
        }
        if(r > cityLen) cityLen = r;
    }
    for(i = 1; i < cityLen; i++)    {
        if(arr[i] != arr[i-1]) printf("%d %d ", i, arr[i]);
    }
    printf("%d 0\n",cityLen);
    return 0;
}