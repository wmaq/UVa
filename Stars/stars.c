#include <stdio.h>
#define MAX 46340 /*max sito number without getting core dumped*/
int sito[1<<16], arr[1<<16];
int limit = 0;
int makeStar(int n){
	int st = n, i;
	for(i = 0; i < limit && arr[i]*arr[i] <= n; i++){
		if(n % arr[i] == 0){
			st -= st/arr[i];
			while(n % arr[i] == 0){
				n /= arr[i];
			} 
		}
	}
	if(n > 1) st -= st/n;
	return st/2;
}
int main(void){
	int points, i, j;
	for(i = 2; i <= MAX; i++){
		if(sito[i] == 0){
			arr[limit++] = i;
			for(j = i*i; j <= MAX; j+=i) sito[j] = 1;
		}
	}
	while(scanf("%d", &points)!=EOF) printf("%d\n", makeStar(points));
	return 0;
}