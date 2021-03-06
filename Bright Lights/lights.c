#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
	int x, y, z;
	unsigned int bitf;
} arr[1<<18], hidden[1<<18];

int n, m;

int gcd(int a, int b){
	return (b == 0) ? a : gcd(b, a % b);
}
int compareX(const void *a, const void *b){
	if( ((struct Point *)a)->x != ((struct Point *)b)->x ){
		return ((struct Point *)a)->x - ((struct Point *)b)->x;
	} else {
		return ((struct Point *)a)->y - ((struct Point *)b)->y;
	}
}
int compareY(const void *a, const void *b){
	if( ((struct Point *)a)->y != ((struct Point *)b)->y ){
		return ((struct Point *)a)->y - ((struct Point *)b)->y;
	} else {
		return ((struct Point *)a)->x - ((struct Point *)b)->x;
	}
}
int compareB(const void *a, const void *b){
	if( ((struct Point *)a)->bitf != ((struct Point *)b)->bitf ){
		return ((struct Point *)a)->bitf > ((struct Point *)b)->bitf ? 1 : -1;
	} else {
		return ((struct Point *)a)->y - ((struct Point *)b)->y;
	}
}
void checkY(void){
	int sub, t, yCnt, height;
	qsort(arr, n, sizeof(arr[0]), &compareY);
	for (yCnt = 0; yCnt < n && arr[yCnt].y == 0; yCnt++);
	if (yCnt == 0) return;
	for (sub = 0; (sub+1) < yCnt && arr[sub+1].x < 0; sub++);
	for (height = -1, t = sub; t >= 0; t--){
		if (arr[t].z <= height) hidden[m++] = arr[t];
		else height = arr[t].z;
	}
	while (sub < yCnt && arr[sub].x <= 0) sub++;
	for (height = -1; sub < yCnt; sub++){
		if (arr[sub].z <= height) hidden[m++] = arr[sub];
		else height = arr[sub].z;
	}
	for (sub = yCnt, t = 0; sub < n;)
		arr[t++] = arr[sub++];
	n = t;
}
void useMagic(void){
	int i, j;
	for(i = 0; i < n; i++){
		t = gcd( abs(arr[i].x), arr[i].y);
		arr[i].bitf = (( abs(arr[i].x) / t )* 10001) + (arr[i].y / t);
		if(arr[i].x < 0) arr[i].bitf |= 0x80000000;
	}
	qsort(arr, n, sizeof(arr[0]), &compareB);
	for(j = 0; j < n; j = t){
		for(t = j+1; t < n && arr[t].bitf == arr[j].bitf; t++);
		for(height = -1, i = j; i < t; i++){
			if(arr[i].z <= height) hidden[m++] = arr[i];
			else height = arr[i].z;
		}
	}
}
int main(void){
	int cnt, ay;
	for(cnt = 1; scanf("%d", &n) == 1 && n; cnt++){
		for(ay = m = 0; ay < n; ay++){
			scanf("%d %d %d", &arr[ay].x, &arr[ay].y, &arr[ay].z);
			if(!arr[ay].x && !arr[ay].y){
				ay--, n--;
			}
		}
		checkY();
		printf("Data set %d:\n", cnt);
		useMagic();
		if(m == 0) printf("All the lights are visible.\n");
		else {
			printf("Some lights are not visible:\n");
			qsort(hidden, m, sizeof(hidden[0]), &compareX);
			for(ay = 0; ay < m; ay++){
				printf("x = %d, y = %d%c\n", hidden[ay].x, hidden[ay].y, ((ay+1) < m) ? ';' : '.');
			}
		}
	}
	return 0;
}