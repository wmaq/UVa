#include <stdio.h>
#include <string.h>
#define MAX 25

char str[MAX], output[MAX];
long long len , fact[MAX];
int pos[MAX], V[MAX];

void DFS(int p, long long x) {
	int i;
	if(p == len) return;
	for(i = 0; i < len; ++i) {
		if( V[i] ) continue;
		if(x > fact[len-p-1]) {
			x -= fact[len-p-1];
		} else {
			V[i] = 1;
			pos[p] = i;
			DFS(p+1, x);
		}
	}
}
int main(void) {
	int i, inp, cas;
	fact[0] = 1;
	for(i = 1; i <= 20; ++i) fact[i] = fact[i-1] * i;
	scanf("%d", &inp);
	for(cas = 1; cas <= inp; ++cas) {
		scanf("%s", str);
		len = strlen(str);
		long long perm;
		scanf("%lld", &perm);
		memset(V,0,sizeof(V));
		DFS(0,perm);
		for(i = 0; i < len; ++i) output[pos[i]] = str[i];
		printf("Case %d: ", cas);
		for(i = 0; i < len; ++i) printf("%c", output[i]);
		printf("\n");
	}
	return 0;
}