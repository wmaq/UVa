#include <stdio.h>

char deck[52][52][2];
int count[52];
int check, comp;

int compare(int x){
	int jump = 0;
	int i;
	comp = check;
	while(jump < x && comp > 0){
		if(count[--comp]) jump++;
	}
	if( jump < x ) return 0;
	if( deck[check][count[check] - 1][0] == deck[comp][count[comp] - 1][0] ||
		deck[check][count[check] - 1][1] == deck[comp][count[comp] - 1][1]){
		deck[comp][count[comp]][0] = deck[check][count[check] - 1][0];
		deck[comp][count[comp]][1] = deck[check][count[check] - 1][1];
		++count[comp];
		--count[check];
		return 1;
	}
	return 0;
}
int main(void){
	char input1[256], input2[256];
	int output[52], n = 0, i, j;
	while( fgets(input1, 256, stdin) ){
		int pos = 0;
		if(input1[0] == '#') break;
		fgets(input2, 256, stdin);
		for(i = 0; i < 26; ++i){
			j = 0;
			while(j < 2){
				if(input1[pos] >= '0' && input1[pos] <= '9' ||
					input1[pos] >= 'A' && input1[pos] <= 'Z') deck[i][0][j++] = input1[pos];
				pos++;
			}
		}
		pos = 0;
		for(i = 26; i < 52; ++i){
			j = 0;
			while(j < 2){
				if(input2[pos] >= '0' && input2[pos] <= '9' ||
					input2[pos] >= 'A' && input2[pos] <= 'Z') deck[i][0][j++] = input2[pos];
				pos++;
			}
		}
		for(i = 0; i < 52; ++i) count[i] = 1;
		check = 1;
		while(check < 52){
			if( count[check] ){
				if( compare(3) == 1 ) check = comp;
				else if( compare(1) == 1) check = comp;
				else check++;
			} else {
				check++;
			}
		}
		n = 0;
		for(i = 0; i < 52; ++i){
			if(count[i] > 0) output[n++] = count[i];
		}
		if(n == 1) printf("%d pile remaining:", n);
		else printf("%d piles remaining:", n);
		for(i = 0; i < n; ++i) printf(" %d", output[i]);
		printf("\n");
	}
	return 0;
}