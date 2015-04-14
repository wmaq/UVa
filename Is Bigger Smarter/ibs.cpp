#include <cstdio>
#include <iostream>
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
	int p = 0;
	while( scanf("%d %d", &eleph[p].A, &eleph[p].B){
		eleph[p].n = p+1;
		p++;
	}
	sort(eleph, eleph + p);
	
	return 0;
}