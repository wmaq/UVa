#include <stdio.h>

int main(void){
	int row, col, per, Z;
	int i, j, k;
	char str1[1<<4], str2[1<<4];
	while( scanf("%d %d", &row, &col) == 2 && (row+col)!=0){
		int seats[30][101] = {}, drinks[30][101] = {};
		scanf("%d", &per);
		while(per--){
			scanf("%s %s", str1, str2);
			int t1, t2;
			t1 = str1[0] - 65;
			sscanf(str1 + 1, "%d", &t2);
			if(str2[0] == '-') drinks[t1][t2-1] = 1;
			else drinks[t1][t2] = 1;
		}
		scanf("%d", &Z);
		while(Z--){
			scanf("%s", str1);
			int t1, t2;
			t1 = str1[0] - 65;
			sscanf(str1 + 1, "%d", &t2);
			seats[t1][t2] = 1;
		}
		int flag = 0;
		for(i = 0; i < row; i++){
			for(j = 1; j <= col; j++){
				if(seats[i][j]!=0){
					if(!drinks[i][j-1]) drinks[i][j-1] = 1;
					else if(!drinks[i][j]) drinks[i][j] = 1;
					else flag = 1;
				}
			}
		}
		printf("%s\n", flag ? "NO" : "YES" );
	}
	return 0;
}