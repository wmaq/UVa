#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int par[1<<19], arr[1<<19];
void setify(int n){
	for(int i = 0; i <= n; ++i){
		par[i] = i;
		arr[i] = 1;
	}
}
int find(int ston){
	if(par[ston] != ston) par[ston] = find(par[ston]);
	return par[ston];
}
void unify(int a, int b){
	a = find(a), b = find(b);
	if(a != b) {
		par[a] = b;
		arr[b] += arr[a];
	}
	printf("%d\n", arr[b]);
}
int main(void){
	int n, fNum;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &fNum);
		map<string, int> le_map;
		setify(fNum *2);
		string f1, f2;
		for(int i = 0, j = 1; i < fNum; ++i){
			cin >> f1 >> f2;
			if(!le_map[f1]) le_map[f1] = j++;
			if(!le_map[f2]) le_map[f2] = j++;
			unify(le_map[f1], le_map[f2]);
		}
	}
	return 0;
}
