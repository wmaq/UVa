#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int top,flag,i;
char str[130],stack[130];

void push(){
    stack[top++] = str[i];
    return;
}
void pop(){
    if(top == 0){
        flag = 1;
        return;
    }
    else if((str[i]==')'&&stack[--top]!='(') || (str[i]==']'&&stack[--top]!='[')){
        flag = 1;
        return;
    }
}
int main(void){
    int n,len;
    scanf("%d ",&n);
    while(n--)
    {
        gets(str);
        top = flag = 0;
        len = strlen(str);
        for(i = 0; i < len; i++){
            if(str[i]=='('||str[i]=='[') push();
            else pop();
            if(flag==1) break;
        }
        if(top > 0) flag = 1;
        if(flag==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}