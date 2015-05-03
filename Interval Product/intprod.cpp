#include <cstdio>
#include <vector>
using namespace std;

inline int LSB(int i) {
    return i & (-i);
}
void fixVal(vector<int> &V, int pos, int n) {
    for(; pos < (int)V.size(); pos += LSB(pos)) V[pos] += n;
}
int outProc(vector<int> &V, int start, int end) {
    int x = 0, y = 0;
    for(start--; start; start -= LSB(start)) y += V[start];
    for(; end; end -= LSB(end)) x += V[end];
    return x - y;
}
int main(void){
    int N, K;
    vector<int> negatives, zeros, saved;
    while( scanf("%d %d\n", &N, &K) != EOF ) {
        negatives.assign(N + 1, 0);
        zeros.assign(N + 1, 0);
        saved.assign(N + 1, 0);
        for(int i = 1; i <= N; i++) {
            scanf("%d", &saved[i]);
            if(saved[i] < 0) fixVal(negatives, i, 1);
            else if(saved[i] == 0) fixVal(zeros, i, 1);
        }
        scanf("\n");
        for(int i = 0; i < K; i++) {
            char c;
            int a, b;
            scanf("%c %d %d\n", &c, &a, &b);
            if(c == 'C') {
                if(saved[a] < 0) fixVal(negatives, a, -1);
                else if(saved[a] == 0) fixVal(zeros, a, -1);
                saved[a] = b;
                if(b < 0) fixVal(negatives, a, 1);
                else if(b == 0) fixVal(zeros, a, 1);
            } else if(c == 'P') {
                if(outProc(zeros, a, b) > 0) printf("0");
                else if(outProc(negatives, a, b) % 2 == 1) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}