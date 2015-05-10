#include <stdio.h>
union U{
	int n;
	char c[4];
} A,B;
int main(void){
	long int N;
	int i;
	while( scanf("%d", &A.n)!=EOF ) {
		for(i = 0; i < 4; ++i) B.c[i] = A.c[3-i];
		printf("%d converts to %d\n", A.n, B.n);
	}
	return 0;
}