#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iterator>

using std::vector;

void topoDFS(vector<bool> &T, const vector<vector<int> > &M, vector<int> &order, int n) {
	T[n] = true;
	for (int i = 0; i < M[n].size(); ++i) {
		int arrow = M[n][i];
		if(T[arrow] == 0) topoDFS(T, M, order, arrow);
	}
	order.push_back(n);
}
int main(void) {
	int n, m;
	while ( (scanf("%d %d", &n, &m)!=EOF) ) {
		if( n == 0 && m == 0) break;
		vector<int> order;
		vector<bool> todo(n+1, 0);
		vector<vector<int> > aM(n+1);
		for (int i = 0; i < m; ++i) {
			int pos, val;
			scanf("%d %d", &pos, &val);
			aM[pos].push_back(val);
		}
		for (int task = 1; task <= n; ++task) {
			if ( todo[task] == 0 ) topoDFS(todo, aM, order, task);
		}
		std::copy(order.rbegin(), order.rend(),std::ostream_iterator<int>(std::cout, " "));
		printf("\n");
	}
	return 0;
}
