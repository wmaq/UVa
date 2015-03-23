#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    for(int testCounter=1; ; testCounter++){
        int N1, N2;
        cin >> N1 >> N2;
        if(N1 == 0 && N2 == 0) break;
        int tower[N1+1][N2+1];
        int row[N1+1], col[N2+1];
        int i, j;
        for(i=0; i < N1+1; i++) tower[i][0] = 0;
        for(j=0; j < N2+1; j++) tower[0][j] = 0;
        for(i=1; i < N1+1; i++) cin >> row[i];
        for(i=1; i < N2+1; i++) cin >> col[i];
        for(i=1; i < N1+1; i++){
            for(j=1; j < N2+1; j++){
                if(row[i] == col[j]) tower[i][j] = tower[i-1][j-1] + 1;
                else tower[i][j] = max(tower[i-1][j], tower[i][j-1]);                   
            }
        }
        cout << "Twin Towers #" << testCounter << endl;
        cout << "Number of Tiles : " << tower[N1][N2] << endl << endl;
    }
}