#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int main(void){
	int cas, N, Q, a;
	int i, j;
	int output[1<<9], arr[1<<17];
	scanf("%d", &cas);
	while(cas--){
		memset(output, 0, sizeof(output));
		scanf("%d %d", &N, &Q);
		for(i = 0; i < N; i++){
			scanf("%d", &arr[i]);
			for(j = 0; j < 231; j++){
				output[j] = MAX(output[j], (j & arr[i]));
			}
		}
		for(i = 0; i < Q; i++){
			scanf("%d", &a);
			printf("%d\n", output[a]);
		}
	}
	return 0;
}