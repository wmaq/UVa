#include <cstdio>

int main(void){
	int n, depth, ballNum;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &depth, &ballNum);
		int out = 0;
		ballNum--;
		for(int i = 1; i < depth; ++i){
			out <<= 1;
			out |= (ballNum & 1);
			ballNum >>= 1;
		}
		out += (1 << (depth-1));
		printf("%d\n", out);
	}
	return 0;
}