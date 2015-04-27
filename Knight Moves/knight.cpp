#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

struct Point{
	int let, num;
}Init, End;
const int dir[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},
					   { 2, 1},{ 1, 2},{-1,2},{-2,1}};
int graph(Point A, Point B){
	int chessTable[9][9]={0};
	queue<Point>Que;
	Que.push(A);
	Point temp, next;
	while( Que.empty() == 0){
		int i;
		temp = Que.front();
		Que.pop();
		if(temp.let == B.let && temp.num == B.num) return chessTable[temp.let][temp.num];
		for(i = 0; i < 8; ++i){
			next.let = temp.let + dir[i][0];
			next.num = temp.num + dir[i][1];
			if(next.let < 1 || next.let > 8 || next.num < 1 || next.num > 8) continue;
			if(chessTable[next.let][next.num] == 0){
				chessTable[next.let][next.num] = chessTable[temp.let][temp.num]+1;
				Que.push(next);
			}
		}
	}
	return chessTable[temp.let][temp.num];
}
int main(void){
	char start[4];
	char dest[4];
	while( (scanf("%s %s", start, dest)!=EOF) ){
		int count;
		Init.let = start[0] - 96;
		Init.num = start[1] - 48;
		End.let = dest[0] - 96;
		End.num = dest[1] - 48;
		count = graph(Init, End);
		printf("To get from %s to %s takes %i knight moves.\n", start, dest, count);
	}
	return 0;
}