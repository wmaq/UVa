#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pot2(a) ((a)*(a))
#define distance(p,q) ( pot2(p.x - q.x) + pot2(p.y - q.y))

struct Point {
	int x, y;
} pts[4];
typedef struct Point vector;
vector vec(struct Point a, struct Point b) {
	vector p = {b.x - a.x, b.y - a.y};
	return p;
}
int dotProd(vector a, vector b) {
	return a.x*b.x + a.y*b.y;
}
int VCS(vector a, vector b) {
	return a.x*b.y - a.y*b.x;
}
int isParallel(vector a, vector b) {
	return VCS(a,b) == 0;
}
int angleCmp(const void *a, const void *b) {
	const struct Point *_a = a;
	const struct Point *_b = b;
	vector n = vec(pts[0], *_a);
	vector m = vec(pts[0], *_b);
	return atan2l(n.y, n.x) < atan2l(m.y, m.x);
}
int pointCmp(const void *a, const void *b){
	int x1 = ((const struct Point*)a)->x;
	int x2 = ((const struct Point*)b)->x;
	int y1 = ((const struct Point*)a)->y;
	int y2 = ((const struct Point*)b)->y;
	if(x1 != x2) return x1-x2;
	return y1-y2;
}
int main(void){
	int t, T, i;
	int cross;
	int len[4];
	scanf("%d", &T);
	for (t = 1; t <= T; t++){
		const char *type;
		for (i = 0; i < 4; i++) scanf("%d %d", &pts[i].x, &pts[i].y);
		qsort(pts, 4, sizeof(struct Point), &pointCmp);
		qsort(pts+1, 3, sizeof(struct Point), &angleCmp);
		for (i = 0; i < 4; i++) len[i] = distance(pts[i], pts[(i+1)%4]);
		cross = dotProd( vec(pts[0], pts[3]), vec(pts[0], pts[1]) ) == 0;
		if (len[0] == len[1] && len[1] == len[2] && len[2] == len[3]){
			if (cross) type = "Square";
			else type = "Rhombus";
		} else if (len[0] == len[2] && len[1] == len[3]){
			if (cross) type = "Rectangle";
			else type = "Parallelogram";
		} else if (isParallel(vec(pts[0], pts[1]), vec(pts[3], pts[2]))
			|| isParallel(vec(pts[0], pts[3]), vec(pts[1], pts[2])))
			type = "Trapezium";
		else
			type = "Ordinary Quadrilateral";

		printf("Case %d: %s\n", t, type);
	}
	return 0;
}