#include <cstdio>

char left[1<<7], right[1<<7];
char str1[55], str2[55];

int cutTheTree(int l, int n, int r){
	int i;
	if(n == l) return 0;
	i = n;
	while( (str2[--i]^str1[r]) != 0 ); /*getting mid*/
	left[ str1[r] ] = cutTheTree(l, i, r+1);
	right[ str1[r] ] = cutTheTree(i+1, n, r-l+i+1);
	return str1[r];
}
void printTree(int p){
	if(!p) return;
	printTree(left[p]);
	printTree(right[p]);
	printf("%c", p);
}
int main(void){
	int n, cas;
	scanf("%d", &cas);
	while(cas--){
		scanf("%d %s %s", &n, &str1[0], &str2[0]);
		int pos = cutTheTree(0, n, 0);
		printTree(pos);
		printf("\n");
	}
	return 0;
}