#include <stdio.h>
int main(void){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        int hours, minutes;
        char c;
        scanf("%d%c%d", &hours, &c, &minutes);
        minutes = (60-minutes)%60;
        hours = 12-hours;
        if(minutes != 0) --hours;
        hours = (hours+12)%12;
        if(hours == 0) hours = 12;
        printf("%02d:%02d\n", hours, minutes);
    }
    return 0;
}