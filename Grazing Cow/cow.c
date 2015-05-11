#include <stdio.h>
#include <math.h>
int main(void){
	int N, L, D;
	double PI = 2.0 * acos(0.0);
	scanf("%d", &N);
	while(N-- && scanf("%d %d", &D, &L) == 2){
		printf("%.3lf\n", PI * L * sqrt((L*L) - (D*D))/4.0);
	}
	return 0;
}