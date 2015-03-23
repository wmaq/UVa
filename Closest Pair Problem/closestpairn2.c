#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2){
	return sqrt(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

int main(void){
	int n;
	while( scanf("%d",&n) ){
		if(n == 0) break;
		double xy[n][2];
		int i,j;
		for(i=0; i < n; i++) scanf("%lf %lf", &xy[i][0], &xy[i][1]);
		if(n == 1){
			printf("INFINITY\n");
			continue;
		}
		double minimal = dist(xy[0][0],xy[0][1],xy[1][0],xy[1][1]);
		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				double temp = dist(xy[i][0],xy[i][1],xy[j][0],xy[j][1]);
				if( temp < minimal )
					minimal = temp;
			}
		}
		if(minimal >= 10000) printf("INFINITY\n");
		else printf("%.4lf\n", minimal);
	}
	return 0;
}