#include <stdio.h>
static struct xy{
double x,y;
} A,B,C,D;
int main(void){
	while( (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y)!=EOF) ){
		if(A.x == C.x && A.y == C.y){printf("%.3lf %.3lf\n", (B.x+D.x)-A.x,  (B.y+D.y)-A.y);}
        else if(A.x == D.x && A.y == D.y){printf("%.3lf %.3lf\n", (B.x+C.x)-A.x,  (B.y+C.y)-A.y);}
        else if(B.x == C.x && B.y == C.y){printf("%.3lf %.3lf\n", (A.x+D.x)-B.x, (A.y+D.y)-B.y);}
        else{printf("%.3lf %.3lf\n", (A.x+C.x)-B.x, (A.y+C.y)-B.y);}
	}
	return 0;
}