#include <iostream>
#include <algorithm>

using namespace std;

struct info{
    int pos;
    double totalFine;
} data[1020];
int compare(info x, info y){
    return x.totalFine > y.totalFine;
}
int main(void){
    int caseCounter, N;
    cin >> caseCounter;
    while(caseCounter--){
        int time[1020], fine[1020];
        cin >> N;
        for(int i=0; i < N; i++){
            cin >> time[i] >> fine[i];
            data[i].totalFine = fine[i]*1.0/time[i];
            data[i].pos = i+1;
        }
        sort(data, data+N, compare);
        cout << data[0].pos;
        for(int i=1; i < N; i++) cout << " " << data[i].pos;
        cout << endl;
        if(caseCounter) cout << endl;
    }
    return 0;
}