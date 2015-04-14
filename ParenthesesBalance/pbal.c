#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char str[129];
	int n, i;
	int temp[4];
	scanf("%d\n", &n);
	while(n--){
		fgets(str, 128, stdin);
		memset(temp, 0, sizeof(temp));
		for(i = 0; str[i]!='\0'; ++i){
			if(str[i]==']'){
               ++temp[1];
               if(str[i-1]=='(') break;
            }
            if(str[i]==')'){
               ++temp[3];
               if(str[i-1]=='[') break;
            }
            if(temp[1] > temp[0]) break;
            if(temp[3] > temp[2]) break;
            if(str[i]=='['){
               ++temp[0];
               if(str[i+1]==')') break;
            }
            if(str[i]=='('){
               ++temp[2];
               if(str[i+1]==']') break;
            }
		}
		if(strlen(str) == 1 || strlen(str)==0) printf("Yes\n");
		else if(temp[0]==temp[1] && temp[2]==temp[3]) printf("Yes\n");
        else printf("No\n");
	}
	return 0;
}