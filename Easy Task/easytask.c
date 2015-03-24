#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matrix{
	int a1,b1,c1,a2,b2,c2;
	double det,detX,detY,X,Y;
}T;

int main(void){
	while( scanf("%d %d %d %d %d %d",&T.a1,&T.b1,&T.c1,&T.a2,&T.b2,&T.c2) ){
		if(T.a1==0 && T.a2==0 && T.b1==0 && T.b2==0 && T.c1==0 && T.c2==0) break;
		
		T.det = T.a1*T.b2 - T.b1*T.a2;
		T.detX = T.c1*T.b2 - T.b1*T.c2;
		T.detY = T.a1*T.c2 - T.a2*T.c1;
		T.X = T.detX/T.det;
		T.Y = T.detY/T.det;

		if(T.X == -0) T.X = 0;
		if(T.Y == -0) T.Y = 0;

		if(T.det != 0) printf("The fixed point is at %.2lf %.2lf.\n", T.X, T.Y);
		else printf("No fixed point exists.\n");
	}
	return 0;
}