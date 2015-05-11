#include <stdio.h>
#include <string.h>

char* myitoa(int value, char* result, int base) {
	if (base < 2 || base > 36) { *result = '\0'; return result; }
	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;
	do{
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
	} while ( value );
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}
int main(void){
	int n, num1, num2, out, i;
	char sign;
	scanf("%d", &n);
	while(n--){
		char bin1[128], bin2[128];
		scanf("%X %c %X", &num1, &sign, &num2);
		if(sign == '+') out = num1 + num2;
		else out = num1 - num2;
		myitoa(num1, bin1, 2);
		myitoa(num2, bin2, 2);
		int diff1 = 0, diff2 = 0;
		if( strlen(bin1)<13 ){
			diff1 = 13 - strlen(bin1);
		}
		if( strlen(bin2)<13 ){
			diff2 = 13 - strlen(bin2);
		}
		printf("%0*d%s %c %0*d%s = %d\n",diff1, 0, bin1, sign, diff2,0, bin2, out);
	}
	return 0;
}