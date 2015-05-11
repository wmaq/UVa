#include <math.h>
#include <stdio.h>
int main(void){
    double l, w, h, theta, alpha;
    double pi = 2*acos(0.0);
    while( scanf("%lf %lf %lf %lf", &l, &w, &h, &theta)!=EOF ){
        double alpha = theta * pi / 180.00   ;
        double a = l;
        double b = l*tan(alpha);
        double c = sqrt(a*a+b*b);
        if( b <= h ){
            double p = (a+b+c)/2. ;
            double heron = sqrt(p*(p-a)*(p-b)*(p-c))*w;
            double out = (l*w*h)-heron;
            printf("%.3lf mL\n", out);
        } else {
            theta =(90-theta)*pi/180.00;
            a = h;
            b = h*tan(theta);
            c = sqrt(a*a+b*b);
            double p = (a+b+c)/2. ;
            double heron = sqrt(p*(p-a)*(p-b)*(p-c))*w;
            printf("%.3lf mL\n",heron);
        }
    }
    return 0;
}