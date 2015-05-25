#include <stdio.h>
#include <stdlib.h>

static struct V{
	int n, reach, deg;
} *vtx;
static struct E{
	int x, y;
} *edg;
static int vtxNum, vtxMax=1024, edgNum, edgMax=1024;

static int createMap(int _a){
	int i;
	for(i = 0; i < vtxNum; i++) if(vtx[i].n == _a) return i;
	if(vtxNum >= vtxMax){
		vtx = (struct V *)realloc(vtx, (vtxMax*=2)*sizeof(struct V) );
	}
	i = vtxNum++;
	vtx[i].n = _a;
	vtx[i].reach = 0;
	vtx[i].deg = 0;
	return i;
}
static void createEdges(int _x, int _y){
	if(edgNum >= edgMax){
		edg = (struct E *)realloc(edg, (edgMax*=2)*sizeof(struct E) );
	}
	edg[edgNum].x = _x;
	edg[edgNum].y = _y;
	vtx[_y].deg++;
	edgNum++;
}
static int checkTree(){
	int i, j;
	static int root;
	if(!vtxNum) return 1;
	for(i = 0, root = -1; i < vtxNum; i++){
		if(!vtx[i].deg){
			if(root < 0) root = i;
			else return 0;
		} else if( vtx[i].deg != 1 ) return 0;
	}
	if(root < 0) return 0;
	vtx[root].reach = 1;
	do{
		for(i = 0, j = 0; i < edgNum; i++){
			if(vtx[ edg[i].x ].reach && !vtx[ edg[i].y ].reach){
				vtx[ edg[i].y ].reach = 1;
				j++;
			}
		}
	} while(j > 0);
	for(i = 0; i < vtxNum; i++) if(!vtx[i].reach) return 0;
	return 1;
}
int main(void){
	static int i, x, y, cas=1;
	vtx = (struct V *)malloc((vtxMax)*sizeof(struct V));
	edg = (struct E *)malloc((edgMax)*sizeof(struct E));
	while(cas++){
		vtxNum=0, edgNum=0;
		for(i = 0; scanf("%d %d", &x, &y) == 2; i++){
			if(x < 0 || y < 0){
				i = -1;
				break;
			}
			if(!x || !y) break;
			createEdges(createMap(x), createMap(y));
		}
		if(i < 0) break;
		printf("Case %d %s a tree.\n", cas-1, checkTree()?"is":"is not");
	}
	return 0;
}