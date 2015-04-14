#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct T{
	int A,B,n;
	T(){}
	bool operator<(const T &name) const{
		if (B != name.B) return B < name.B;
        return A > name.A;
	}
};

int main(void){
	struct T eleph[1001];
    int arr[1001];
    int temp[1001];
	int p = 0, no1 = 0, x = 0;
	while( scanf("%d %d", &eleph[p].A, &eleph[p].B) == 2){
		eleph[p].n = p+1;
		p++;
	}
	sort(eleph, eleph + p);
	memset(arr, -1, sizeof(arr));
    for(int i = 0; i < p; i++){
        temp[i] = 1;
        for(int j = 0; j < i; j++){
            if(eleph[j].B < eleph[i].B && eleph[j].A > eleph[i].A && temp[j]+1 > temp[i]){
                temp[i] = temp[j] + 1;
                arr[i] = j;
            }
        }
        if(temp[i] > no1){
            no1 = temp[i];
            x = i;
        }
    }
    printf("%d\n", no1);
    for(int i = x; i!=-1 ; i = arr[i]) printf("%d\n", eleph[i].n);
	return 0;
}