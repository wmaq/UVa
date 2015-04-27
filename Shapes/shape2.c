#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define sq(a) ((a)*(a))
#define distance(p,q) ( sq(p.x - q.x) + sq(p.y - q.y))

struct Point {
	int x, y;
} pts[4];
typedef struct Point vector;

/*int operator < (const Point &a, const Point &b){
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}*/
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
int compare(const void *a, const void *b) {
	const struct Point *_a = a;
	const struct Point *_b = b;
	if(_a->x != _b->x) return _a->x < _b->x;
	return _a->y < _b->y;
}
int angleCmp(const void *a, const void *b) {
	const struct Point *_a = a;
	const struct Point *_b = b;
	vector n = vec(pts[0], *_a);
	vector m = vec(pts[0], *_b);
	return atan2l(n.y, n.x) < atan2l(m.y, m.x);
}
int main(void){
	int t, T, i;
	int cross;
	int len[4];
	scanf("%d", &T);
	for (t = 1; t <= T; t++){
		const char *type;
		for (i = 0; i < 4; i++) scanf("%d %d", &pts[i].x, &pts[i].y);
		//qsort(pts, 5, sizeof(struct Point), &compare);
		qsort(pts+1, 4, sizeof(struct Point), &angleCmp);
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