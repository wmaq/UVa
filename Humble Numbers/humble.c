#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

int main(void){

    int humble[5842];    
    int n,i,dziel2=0,dziel3=0,dziel5=0,dziel7=0;
    
    humble[0]=1;
    
    for(i=1;i<5842;i++){
        humble[i]=min(min(2*humble[dziel2],3*humble[dziel3]),min(5*humble[dziel5],7*humble[dziel7])); 
        if(humble[i]==2*humble[dziel2]) dziel2++;
        if(humble[i]==3*humble[dziel3]) dziel3++;
        if(humble[i]==5*humble[dziel5]) dziel5++;
        if(humble[i]==7*humble[dziel7]) dziel7++;
    }
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        printf("The %d",n); 
        if(n%10==1&&(n/10)%10!=1) printf("st");
        else if(n%10==2&&(n/10)%10!=1) printf("nd");
        else if(n%10==3&&(n/10)%10!=1) printf("rd");
        else printf("th");
        printf(" humble number is %d.\n",humble[n-1]);
    }
    return 0;
}