#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

struct Point{
	double x,y;
	Point () {}
	bool operator<(const Point &p) const{
		if(x>p.x) return false;
		else if(x == p.x) return x<p.x;
		else return true;
	}
} p[10020];

double clDist;
const double MAX_SIZE = 2000000000;

double dist(Point a, Point b){
	return ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
}
double merge(int a , int m, int b){
	for(int i = m; i >= a; i--){
		if( pow((p[i].x - p[m].x),2) >= clDist ) break;
		for(int j = m+1; j <= b; j++){
			if( pow((p[i].x - p[j].x),2) >= clDist) break;
			clDist = min(clDist, dist(p[i],p[j]));
		}
	}
}
double divide(int a, int b){
	if(a < b){
		if(b - a == 1) return dist(p[a],p[b]);
		int m = (a+b)>>1;
		double left = divide(a,m);
		double right = divide(m+1,b);
		clDist = min(clDist, min(left,right));
		merge(a,m,b);
		return clDist;
	}
	return MAX_SIZE;
}
int main(void){
	int n;
	while(scanf("%d", &n)){
		if(!n) break;
		for(int i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
		sort(p, p + n);
		clDist = MAX_SIZE;
		clDist = sqrt(divide(0,n-1));
		if(clDist >= 10000) printf("INFINITY\n");
		else printf("%.4lf\n", clDist);
	}
	return 0;
}