#include <stdio.h>

double dist(double x1, double y1, double x2, double y2){
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(void){
	int N,a,i;
	while( scanf("%d %d",&N, &a) != EOF ){
		if(N == 0 || a == 0) break;
		int M = 0;
		double p=a*a;
		for(i = 0; i < N; i++){
			double x,y;
			scanf("%lf %lf", &x, &y);
			if( (dist(x,y,0,0) <= p) &&
				(dist(x,y,0,(double)a) <= p) &&
				(dist(x,y,(double)a,0) <= p) &&
				(dist(x,y,(double)a,(double)a) <= p)) ++M;
		}
		printf("%.5lf\n", ((double)M/(double)N)*p);
	}
	return 0;
}