#include <stdio.h>
int par;
void base(int x) {
	if (x > 1) base(x / 2);
	if (x % 2) printf("1"), par++;
	else printf("0");
}
int main(void) {
	int n;
	while (scanf("%d", &n)!=EOF) {
		if(n==0) break;
		par=0;
		printf("The parity of ");
		base(n);
		printf(" is %d (mod 2).\n", par);
	}
	return 0;
}