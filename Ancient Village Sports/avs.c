#include <stdio.h>
#include <math.h>

int main(void){
   int caseIterator=0, n;
   double area, piNum=2*acos(0);
   while( (scanf("%d %lf", &n, &area)!=EOF) ){
      if(n < 3) break;
      double sR = sqrt(area/(n*tan(piNum/n)));
      double c = (2*area)/(sR*n);
      double bR = c/(2*sin(piNum/n));
      
      double area1 = (bR*bR*acos(-1))-area;
      double area2 = area-(sR*sR*acos(-1));
      caseIterator++;

      printf("Case %d: %.5lf %.5lf\n", caseIterator, area1, area2);
   }
   return 0;
}