#include <stdio.h>
#include <string.h>

int main(void) {
	int n, i, j, cas = 0;
	char input[1<<7][1<<7], output[1<<7][1<<7];
	while( scanf("%d", &n) == 1 && n != 0) {
		int tab[1<<7] = {};
		int count = 0, flag = 1;
		char fixed[1<<7], type[1<<7];
		for(i = 0; i < n; ++i) scanf("%s %s", input[i], output[i]);
		for(i = '0'; i <= '9'; i++) tab[i] = 1;
		for(i = 'A'; i <= 'Z'; i++) tab[i] = 1;
		for(i = 'a'; i <= 'z'; i++) tab[i] = 1;
		for(i = 0; i < n; ++i) {
			for(j = 1; output[i][j] != 0; ++j) {
				if(input[i][j] != output[i][j]) tab[ input[i][j] ] = 0;
				else if(tab[ input[i][j] ] != 0) tab[ input[i][j] ] |= 2;
			}
		}
		for(i = '0', j = '0' - 1; i < 128; ++i) {
			if( tab[i] == 3 ) {
				while(j < i) {
					if( tab[j] == 1 ) fixed[count++] = j;
					j++;
				}
				fixed[count++] = i;
			}
		}
		if( !count ) {
			for(i = '0'; i < 128; ++i) {
				if( tab[i] == 1 ) {
					fixed[count++] = i;
					break;
				}
			}
		}
		fixed[count] = '\0';
		type[0] = '%', type[1] = '[';
		for(i = 0; i < count; ++i) type[i+2] = fixed[i];
		type[count+2] = ']', type[count+3] = '\0';
		if( !count ) flag = 0;
		for(i = 0; i < n && flag != 0; ++i) {
			char str[1<<7] = {};
			int len = strlen(input[i]) - 1;
			input[i][len] = '\0';
			sscanf(input[i]+1, type, str+1);
			str[0] = '"';
			int lens = strlen(str);
			str[lens] = '"', str[lens+1] = '\0';
			int equal = !strcmp(str, output[i]);
			flag &= equal;
		}
		printf("Case %d: %s\n", ++cas, flag != 0 ? type+1 : "I_AM_UNDONE");
	}
	return 0;
}