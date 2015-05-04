#include <cstdio>
#include <vector>
using namespace std;
const int INF = 0x3FFFFFFF;
struct E{
	int A, B, Del;
}edges[101];
int prev[12], now[12];
int p;
bool relax(E &edge) {
	if(now[edge.A] + edge.Del < now[edge.B]){
		now[edge.B] = now[edge.A] + edge.Del;
		prev[edge.B] = edge.A;
		return true;
	}
	return false;
}
void BelFord(int &N) {
	for(int i = 0; i <= N-1; ++i) {
		bool fl = false;
		for(int j = 0; j < p; ++j){
			if( relax(edges[j]) ) fl = true;
		}
		if(fl == false) return;
	}
}
void output(int &start, int &end) {
	static int cases = 1;
	printf("Case %d: Path =", cases++);
	vector<int> out;
    int i = end;
    while(i != start) {
        i = prev[i];
        out.push_back(i);
    }
    for(int i = out.size() - 1; i >= 0; --i) printf(" %d", out[i]);
    printf(" %d; %d second delay\n", end, now[end]);
}
int main(void) {
	int N, start, end;
	while(scanf("%d", &N) != EOF && N != 0) {
		p = 0;
		for(int i = 1, n; i <= N; ++i) {
            scanf("%d", &n);
            for(int j = 0; j < n; ++j) {
                scanf("%d %d", &edges[p].B, &edges[p].Del);
                edges[p++].A = i;
            }
        }
        scanf("%d %d", &start, &end);
        for(int i = 1; i <= N; ++i) {
			now[i] = INF;
			prev[i] = 0;
		}
		now[start] = 0;
        BelFord(N);
        output(start, end);
	}
	return 0;
}