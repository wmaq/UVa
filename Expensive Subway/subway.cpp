#include <iostream>
#include <cstdio>
#include <map>
#include <cstdlib>
using namespace std;

struct edge{
	int A, B, usd;
} roads[1<<22];
int par[1<<19], arr[1<<19];
void setify(int n){
	for(int i = 0; i <= n; ++i){
		par[i] = i;
		arr[i] = 1;
	}
}
int find(int ston){
	return par[ston] == ston ? ston : par[ston] = find(par[ston]);
}
bool unify(int a, int b){
	a = find(a), b = find(b);
	if(a != b) {
		if(arr[a] > arr[b]) {
			par[b] = a;
			arr[a] += arr[b];
		} else {
			par[a] = b;
			arr[b] += arr[a];	
		}
		return true;
	}
	return false;
}
int compare(const void *a, const void *b){
	edge *_a, *_b;
	_a = (edge *)a;
	_b = (edge *)b;
	return _a->usd - _b->usd;
}
int main(void){
	int n, m, cas = 0;
	string str="";
	while(scanf("%d %d", &n, &m)==2 && n){
		int out = 0, check = 0;
		map<string, int> le_map;
		for(int i = 0; i < n; i++){
			cin >> str;
			le_map[str] = i;
		}
		for(int i = 0; i < m; i++){
			cin >> str;
			roads[i].A = le_map[str];
			cin >> str;
			roads[i].B = le_map[str];
			scanf("%d", &roads[i].usd);
		}
		cin >> str;
		setify(n);
		qsort(roads, m, sizeof(edge), compare);
		for(int i = 0; i < m; ++i){
			if(unify(roads[i].A, roads[i].B) == true){
				out += roads[i].usd;
				check++;
				if(check == n-1) break;
			}
		}
		if(check == n-1) printf("%d\n", out);
		else printf("Impossible\n");
	}
	return 0;
}
