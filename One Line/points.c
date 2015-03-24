#include <stdio.h>

struct xy{
	int x1, y1, x2, y2, x3, y3;
};

int main(void){
	int N, i;
	scanf("%d", &N);
	struct xy points[N];
	for(i = 0; i < N; i++){
	 	scanf("%d %d %d %d %d %d", 
		&points[i].x1, &points[i].y1, &points[i].x2,
		&points[i].y2, &points[i].x3, &points[i].y3);
	 	int det = points[i].x1 * points[i].y2 + points[i].x2 * points[i].y3 +
	 	    points[i].x3 * points[i].y1 -	points[i].x3 * points[i].y2 -
	 	    points[i].x1 * points[i].y3 - points[i].x2 * points[i].y1;
	 	if(det == 0) printf("TAK\n");
	 	else printf("NIE\n");
	}
	return 0;
}