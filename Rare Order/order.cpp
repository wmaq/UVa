#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

const int MAX = 30;
vector< vector<int> > T;
bitset<MAX> checked, flagged;
vector<int> output;

void DFS(int x) {
	checked.set(x);
	for(int i = 0; i < (int) T[x].size(); i++) {
		int temp = T[x][i];
		if(!checked[temp]) DFS(temp);
	}
	output.push_back(x);
}
int main(void) {
	char str[MAX], s[MAX];
	T.assign(MAX, vector<int>());
	scanf("%s", s);
	while(scanf("%s", str), strcmp(str, "#")) {
		for(int i = 0; i < (int)strlen(str) && i < (int)strlen(s); i++) {
			if(s[i] != str[i]) {
				flagged.set(s[i] - 65);
				flagged.set(str[i] - 65);
				T[s[i] - 65].push_back(str[i] - 65);
				break;
			}
		}
		strcpy(s, str);
	}
	for(int i = 0; i < 26; i++) {
		if (!checked[i] && flagged[i]) DFS(i);
	}
	for(int i = output.size() - 1; i >= 0; i--) printf("%c", output[i] + 65);
	printf("\n");
	return 0;
}