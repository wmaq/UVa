#include <stdio.h>
#include <math.h>

int countFlips(int n,long int tab[]){
   int i,j,count=0;
   if( n==0 || n==1 ) return 0;
   for( i = 0; i < n-1; i++ ){
      for( j = i; j < n; j++ ){
         if( tab[i] > tab[j] ) count++;
      }
   }
   return count;
}
int main(void){
   int n,i;
   long int tab[1002];
   while(scanf("%d",&n) != EOF){
      int flipNumber=0;
      for(i =0; i<n ; i++){
         scanf("%ld",&tab[i]);
      }
      flipNumber = countFlips(n, tab);
      printf("Minimum exchange operations : %d\n",flipNumber);
   }
   return 0;
}