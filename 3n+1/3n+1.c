#include <stdio.h>

void sw(int *x,int *y){
	int z=*x; *x=*y; *y=z; return;
}
int func(int n){
	int j=1;
	while(n!=1){
		if(n%2==0)	n=n/2;
		else n=3*n+1;
		j++;
	}
	return j;
}
int main(void){
	int x,y,x2,y2;
	int max,temp,i;
	while(scanf("%d %d",&x,&y)!=EOF){
		x2=x; y2=y;
		if(x>y)	sw(&x,&y);
		max=func(x);
		for(i=x ; i<=y ; i++){
			temp = func(i);
			if(temp>max) max=temp;
		}
		printf("%d %d %d\n",x2,y2,max);
	}
	return 0;
}
