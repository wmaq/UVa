#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 1001;
int arr[MAX_LENGTH][MAX_LENGTH], cuts[MAX_LENGTH], V[MAX_LENGTH][MAX_LENGTH];

int checkTree(int a, int b){
    int i, min_n = 1<<15;
    if(a+1 == b) return 0;
    if(V[a][b] != 0) return arr[a][b];
    for(i = a+1; i < b; i++) min_n = min(min_n, checkTree(a,i) + checkTree(i,b) + cuts[b]-cuts[a]);
    V[a][b] = 1;
    return arr[a][b] = min_n;
}
int main(void){
    int len, n, i;
    while(scanf("%d", &len) != EOF && len) {
        scanf("%d", &n); 
        memset(cuts, 0, sizeof(cuts));
        memset(V, 0, sizeof(V));
        cuts[0] = 0;
        for(i = 1; i <= n; i++) scanf("%d", &cuts[i]);
        cuts[n+1] = len;
        printf("The minimum cutting is %d.\n", checkTree(0, n+1));
    }
    return 0;  
}
