#include <stdio.h>
 
int matrix[5][5];
int solution[10];
 
void perm(int x, int count){
    int i;
    solution[count] = x;
 
    if ( count == 8 ){
        for ( i = 0; i < 9; i++ ) printf ("%d", solution[i] + 1);
        printf ("\n");
        return;
    }
    for ( i = 0; i < 5; i++ ){
        if (matrix[x][i]){
            matrix[x][i]=matrix[i][x]=0;
            perm(i,count+1);
            matrix[x][i]=matrix[i][x]=1;
        }
    }
}
int main(void){
    int i,j;
    for ( i = 0; i < 5; i++ ){
        for ( j = 0; j < 5; j++ ){
            matrix[i][j] = 0;
        }
    }
    matrix[0][1]=matrix[0][2]=matrix[0][4]=1;
    matrix[1][0]=matrix[1][2]=matrix[1][4]=1;
    matrix[2][0]=matrix[2][1]=matrix[2][3]=matrix[2][4]=1;
    matrix[3][2]=matrix[3][4]=1;
    matrix[4][0]=matrix[4][1]=matrix[4][2]=matrix[4][3]=1;
    perm(0, 0);
    return 0;
}
