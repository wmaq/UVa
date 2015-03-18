#include <iostream>
#include <stack>

using namespace std;

int main(void){
	int N,out[1005];
	while( cin >> N ){
		if(N == 0) break;
		while( cin >> out[0] ){
			if(out[0] == 0){ cout << endl; break; }
			stack < int > station;
			int outIterator = 0 ,coachPos = 1;
			for(int i = 1; i < N; ++i)	cin >> out[i];
			while( coachPos <= N ){
				station.push(coachPos);
				while( !station.empty() && station.top() == out[outIterator] ){
					outIterator++;
					station.pop();
					if(outIterator >= N) break;
				}
				coachPos++;
			}
			if( station.empty() ) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}