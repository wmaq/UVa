#include <stdio.h>
#include <string.h>
int len, t;
char str[1<<7];
char nextChar(void){
	if(t >= len) return '/';
	return str[t++];
}
int slumpify(void){
	char next = nextChar();
	if(next != 'D' && next != 'E') return 0;
	next = nextChar();
	if(next != 'F') return 0;
	while( (next = nextChar()) == 'F');
	if(next == '/') return 0;
	if(next == 'G') return 1;
	if(t > 0) t--;
	return slumpify();
}
int slimpify(void){
	char next = nextChar();
	if(next != 'A') return 0;
	next = nextChar();
	if(next == '/') return 0;
	if(next == 'H') return 1;
	if(next == 'B')	return slimpify() && (nextChar() == 'C');
	if(t > 0) t--;
	return slumpify() && (nextChar() == 'C');
}
int slurpify(void){
	return slimpify() && slumpify() && (nextChar() == '/');
}
int main(void){
	int cas;
	scanf("%d", &cas);
	printf("SLURPYS OUTPUT\n");
	while(cas--){
		scanf("%s", &str[0]);
		len = strlen(str);
		t = 0;
		if(slurpify()!=0) printf("YES\n");
		else printf("NO\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}