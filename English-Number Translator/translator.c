#include <stdio.h>
#include <string.h>

int main(void){
	long long int value, million, thousand, hundred;
	int sign, i, k;
	char word[31][100] = {"one", "two", "three",
		"four", "five", "six", "seven", "eight",
		"nine", "ten", "eleven", "twelve", "thirteen",
		"fourteen", "fifteen", "sixteen", "seventeen",
		"eighteen", "nineteen", "twenty", "thirty",
		"forty", "fifty", "sixty", "seventy", "eighty",
		"ninety", "hundred", "thousand", "million", "negative"};
	
	char input[303];
	char *p;	
	while ( fgets(input, 300, stdin) ) {
		value = sign = 0;
		million = thousand = 1;
		p = strtok(input, " \n\t\r");
		while (p) {		
			for(i = 0; i < 31; ++i) {
				if (strcmp(word[i], p) == 0) {
					for(k = 0; k < 20; ++k) {
						if(i == k) value += (k+1);
					}
					for(k = 0; k < 7; ++k) {
						if(i == k+20) value+=(k*10)+30;
					}
					if(i == 27) value*=100;
					else if (i == 28) {
						thousand = value * 1000;
						value = 0;
					} else if (i == 29) {
						million = value * 1000000;
						value = 0;
					}
					if (i == 30) sign = 1;
					break;
				}
			}
			p = strtok(NULL," \n\t\r");
		}	
		if (million > 1) value += million;
		if (thousand > 1) value += thousand;
		if (sign) printf("-%lld\n", value);
		else printf("%lld\n",  value);;
	}
	return 0;
}