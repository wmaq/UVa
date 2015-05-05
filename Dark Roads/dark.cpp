#include <cstdio>
#include <cstdlib>

const int MAX = 1<<19;

struct Routes{
	int A, B, val;
} roads[MAX];
int parents[MAX], arr[MAX];

void connect(int a, int b){
	if(arr[a] > arr[b]) {
		arr[a] += arr[b];
		parents[b] = a; 
	} else {
		arr[b] += arr[a];
		parents[a] = b;
	}
}
int find(int ston){
	if(parents[ston] != ston) parents[ston] = find(parents[ston]);
	return parents[ston];
}
bool unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b) {
		connect(a, b);
		return true;
	}
	return false;
}
int compVal(const void *a, const void *b){
	Routes *_a, *_b;
	_a = (Routes *)a;
	_b = (Routes *)b;
	return _a->val - _b->val;
}
int main(void){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		if(!n && !m) break;
		int out = 0, temp = 0;
		bool fl;
		for(int i = 0; i < m; ++i) {
			scanf("%d %d %d", &roads[i].A, &roads[i].B, &roads[i].val);
            roads[m+i].A = roads[i].B;
            roads[m+i].B = roads[i].A;
            roads[m+i].val = roads[i].val;
            out += roads[i].val;
		}
		m *= 2;
		qsort(roads, m, sizeof(Routes), compVal);
		for(int i = 0; i <= n; ++i){
			parents[i] = i;
			arr[i] = 1;
		}
		for(int i = 0; i < m; ++i){
			fl = unite(roads[i].A, roads[i].B);
			out -= fl * roads[i].val;
			temp += (int)fl;
			if(temp == n-1) break;
		}
		printf("%d\n", out);
	}
	return 0;
}