#include <stdio.h>

int main(void){
	unsigned int x,y;
	while( (scanf("%u %u", &x, &y)!=EOF) ){
		unsigned int result = x ^ y;
		printf("%u\n", result);
	}
	return 0;
}