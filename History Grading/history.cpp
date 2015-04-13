#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	int n, p;
	int pattern[50], seq[50];
	int LCS[50][50] = {0};

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> p;
		pattern[p] = i;
	}
	while( cin >> p || !cin.eof() ){
		seq[p] = 1;
		int x = 0;
		for(int i = 2; i <= n; ++i){
			cin >> p;
			seq[p] = i;
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(pattern[i]==seq[j]) LCS[i][j] = LCS[i-1][j-1] + 1;
				else LCS[i][j] = max( LCS[i-1][j], LCS[i][j-1] );
				if(LCS[i][j] > x) x = LCS[i][j];
			}
		}
		cout << x << endl;
	}
	return 0;
}