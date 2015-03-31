#include <stdio.h>

int main(void){
  int n,i,caseNum = 0;
  int p[15];
  p[0] = 1;
  for(i = 1; i < 15; i++) p[i] = (p[i-1] << 1);
  while( scanf("%d", &n) ){
    if(n < 0) break;
    caseNum++;
    for(i = 0; i < 15; i++){
      if(p[i] >= n){
      	printf("Case %d: %d\n", caseNum, i);
        break;
      }
    }
  }
  return 0;
}