#include <queue>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX = 100, DAY = 18, EVENING = 6;
const int HR = 24, NEG = -1;

struct Vlad{
	int city, time, bloodL;
	bool operator<(const Vlad &T) const{
		return bloodL > T.bloodL;
	}
};
struct trackInfo{
	int leave, arrive, fin;
};
vector<trackInfo> tracks[MAX + 1];

int checkBlood(int beg, int fin) {
	priority_queue<Vlad> stats;
	stats.push(
		(Vlad){
			beg, DAY, 0
		});
	while( !stats.empty() ) {
		Vlad now = stats.top();
		stats.pop();
		if(now.city == fin) return now.bloodL;
		for(int i = 0; i < tracks[now.city].size(); i++) {
			int bloodUsage = now.bloodL;
			if(now.time > tracks[now.city][i].leave) bloodUsage++;
			stats.push(
				(Vlad){
					tracks[now.city][i].fin, tracks[now.city][i].arrive, bloodUsage
				});
		}
	}
	return NEG;
}
int main(void) {
	int n, trackInfos, cases = 1, beg, fin, leave, travelT;
	string start, end;
	scanf("%d", &n);
	while(n--) {
		map<string, int> cities;
		for(int i = 0; i < MAX + 1; i++) tracks[i].clear();
		scanf("%d", &trackInfos);
		for(int i = 1; i <= trackInfos; i++) {
			cin >> start >> end;
			scanf("%d %d", &leave, &travelT);
			if(cities.find(start) == cities.end())	{
				beg = cities.size();
				cities[start] = beg;
			} 
			else beg = cities[start];
			if(cities.find(end) == cities.end()) {
				fin = cities.size();
				cities[end] = fin;
			}
			else fin = cities[end];
			leave += (leave <= EVENING ? HR : 0);
			if(leave >= DAY	&& (leave + travelT) <= (HR + EVENING))
				tracks[beg].push_back(
					(trackInfo){
						leave, (leave + travelT), fin
					});
		}
		cin >> start >> end;
		printf("Test Case %d.\n", cases++);
		if(start == end) {
			printf("Vladimir needs 0 litre(s) of blood.\n");
			continue;
		}
		if(cities.find(start) == cities.end() || cities.find(end) == cities.end()) {
			printf("There is no route Vladimir can take.\n");
			continue;
		}
		beg = cities[start];
		fin = cities[end];
		int bloodL = checkBlood(beg, fin);
		if(bloodL == NEG) printf("There is no route Vladimir can take.\n");
		else printf("Vladimir needs %d litre(s) of blood.\n", bloodL);
	}
	return 0;
}