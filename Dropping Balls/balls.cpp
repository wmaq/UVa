#include <stdio.h>

int main(void){
	int n, depth, ballNum,i;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &depth, &ballNum);
		int x = 0;
		ballNum--;
		for(i = 1; i < depth; ++i){
			x <<= 1;
			x |= (ballNum & 1);
			ballNum >>= 1;
		}
		x += (1 << (depth-1));
		printf("%d\n", x);
	}
	return 0;
}