#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

class Point{
private:
	int x , y;
public:
	bool ifZero(Point &A);
	static bool compareY(const Point &A, const Point &B);
	static bool compareX(const Point &A, const Point &B);
	bool colin(const Point &A, const Point &B, const Point &C);
	bool doesPrevExist(const Point &A, const Point &B, std::vector<Point>line);
	void findAll(std::vector<Point> &R2);
	void print(std::vector<Point> &R2, bool firstL);
	friend std::istream &operator>>(std::istream &input, Point &XY){
		input >> XY.x >> XY.y;
		return input;
	}
};
bool Point::ifZero(Point &A){
	std::cin >> A;
	if(A.x == 0 && A.y == 0) return false;
	return true;
}
bool Point::compareY(const Point &A, const Point &B){
	return (A.y < B.y);
}
bool Point::compareX(const Point &A, const Point &B){
	return (A.x < B.x);
}
bool Point::colin(const Point &A, const Point &B, const Point &C){
	return ((A.x*B.y)+(B.x*C.y)+(C.x*A.y))==((A.x*C.y)+(B.x*A.y)+(C.x*B.y));
}
bool Point::doesPrevExist(const Point &A, const Point &B, std::vector<Point>line){
	for(int i=0; i < line.size(); i+=2){
		if( colin(A, B, line[i]) && colin(A, B, line[i+1])) return true;
	}
	return false;
}
void Point::print(std::vector<Point> &R2, bool firstL){
	if( firstL ) printf("The following lines were found:\n");
	for(int i=0; i < R2.size(); ++i) printf("(%4d,%4d)", R2[i].x , R2[i].y);
	printf("\n");
}
void Point::findAll(std::vector<Point> &R2){
	bool notFound = true, firstL = true;
	std::stable_sort(R2.begin(), R2.end(), compareY);
	std::stable_sort(R2.begin(), R2.end(), compareX);
	std::vector<Point> p;
	for(int i=0; i < R2.size(); ++i){
		for(int j=i+1; j < R2.size(); ++j){
			if(doesPrevExist(R2[i], R2[j], p)) continue;
			std::vector<Point> line;
			line.push_back(R2[i]);
			line.push_back(R2[j]);
			for(int k=j+1; k < R2.size(); ++k){
				if( colin(R2[i], R2[j], R2[k]) ){
					notFound = 0;
					line.push_back(R2[k]);
				}
			}
			if( line.size() > 2 ){
				print(line, firstL);
				firstL = false;
				p.push_back(line[0]);
				p.push_back(line[1]);
			}
		}
	}
	if( notFound ) printf("No lines were found\n");
}
int main(void){
	while(1){
		std::vector<Point> points;
		Point XY;
		while(XY.ifZero(XY)) points.push_back(XY);
		if(!points.size()) break;
		XY.findAll(points);
	}
	return 0;
}