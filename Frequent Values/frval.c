#include <stdio.h>
#include <stdlib.h>

struct Tree{ 
	int M, L, R; 
}treeArray[1<<18];

int array[1<<17];

int max(int a, int b){
	return a > b ? a : b;
}

void makeTree(int Node, int i, int j){
	if(i == j){
		treeArray[Node].M = treeArray[Node].L = treeArray[Node].R = 1;
		return;
	}
	int mid = (i + j) >> 1;
	int lCh = Node << 1;
	int rCh = lCh + 1;
	makeTree(lCh, i, mid);
	makeTree(rCh, mid+1, j);
	treeArray[Node].M = max(max(treeArray[lCh].M, treeArray[rCh].M), 
		(treeArray[lCh].R+treeArray[rCh].L)*(array[mid]==array[mid+1]));
	treeArray[Node].L = array[i] == array[mid+1] ? mid-i+1 + treeArray[rCh].L : treeArray[lCh].L;
	treeArray[Node].R = array[mid] == array[j]? (j-mid) + treeArray[lCh].R : treeArray[rCh].R;
}

int searchTree(int Node, int i, int j, int p, int q){
	if(i == p && j == q) return treeArray[Node].M;
	int mid = (i + j) >> 1, lCh = Node << 1, rCh = lCh + 1;
	if(q <= mid) return searchTree(lCh, i, mid, p, q);
	else if(p > mid) return searchTree(rCh, mid+1, j, p, q);
	else {
		int r1 = searchTree(lCh, i, mid, p, mid);
		int r2 = searchTree(rCh, mid+1, j, mid+1, q);
		int pL = array[p]==array[mid] ? mid-p+1 : treeArray[lCh].R;
		int pR = array[mid+1]==array[q] ? q-mid : treeArray[rCh].L;
		return max(max(r1, r2), (pL + pR)*(array[mid]==array[mid+1]));
	}
}

int main(void){
	int n, q, i, j;
	while(scanf("%d", &n) == 1 && n) {
		scanf("%d", &q);
		for(i = 0; i < n; i++) scanf("%d", &array[i]);
		makeTree(1, 0, n-1);
		while(q--) {
			scanf("%d%d", &i, &j);
			printf("%d\n", searchTree(1, 0, n-1, i-1, j-1));
		}
	}
	return 0;
}