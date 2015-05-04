#include <stdio.h>
#include <string.h>
#define BIG 655536
#define INF 0x3FFFFFFF

char cityNames[1<<7][1<<5], hways[1<<8][1<<5];
int cityCount, hwaysCount;
int dist[1<<7][1<<7], next[1<<7][1<<7], route[1<<7][1<<7];

int fillCities(char *str) {
	int i;
	for (i = 0; i < cityCount; i++) if(!strcmp(cityNames[i], str)) return i;
	strcpy(cityNames[cityCount], str);
	return cityCount++;
}
int fillHWays(char *str) {
	int i;
	for (i = 0; i < hwaysCount; i++) if(!strcmp(hways[i], str)) return i;
	strcpy(hways[hwaysCount], str);
	return hwaysCount++;
}
void print(int x, int y) {
	int i;
	printf("From                 To                   Route      Miles\n");
	printf("-------------------- -------------------- ---------- -----\n");
	for(i = x; i != y; i = next[i][y])
		printf("%-20s %-20s %-10s %5d\n", cityNames[i], cityNames[next[i][y]], 
			hways[route[i][next[i][y]]], dist[i][next[i][y]] );
	printf("                                                     -----\n");
	printf("                                          Total      %5d\n", dist[x][y]);
}
int main(void) {
	static char buf[BIG], str1[1<<10], str2[1<<10], str3[1<<10];
	int i, j, k, x, y, z;
	cityCount = 0, hwaysCount = 0;
	for (i = 0; i < 128; i++) {
		for (j = 0; j < 128; j++) {
			dist[i][j] = INF;
			route[i][j] = -1;
			next[i][j] = j;
		}
		dist[i][i] = 0;
	}
	while(fgets(buf, BIG, stdin)) {
		buf[strcspn(buf, "\n")] = '\0';
		if(sscanf(buf, "%[^,],%[^,],%[^,],%d", str1, str2, str3, &z) != 4) break;
		x = fillCities(str1);
		y = fillCities(str2);
		if (dist[x][y] <= z) continue;
		dist[x][y] = dist[y][x] = z;
		route[x][y] = route[y][x] = fillHWays(str3);
	}
	for (k = 0; k < cityCount; k++) {
		for (i = 0; i < cityCount; i++) {
			for (j = i + 1; j < cityCount; j++) {
				if ((dist[i][k] + dist[k][j]) >= dist[i][j]) continue;
				dist[i][j] = dist[i][k] + dist[k][j];
				dist[j][i] = dist[i][j];
				next[i][j] = next[i][k];
				next[j][i] = next[j][k];
			}
		}
	}
	for(k = 0; fgets(buf, BIG, stdin); k++) {
		buf[strcspn(buf, "\n")] = '\0';
		if(sscanf(buf, "%[^,],%[^,]", str1, str2) != 2) break;
		x = fillCities(str1);
		y = fillCities(str2);
		printf("\n\n");
		print(x, y);
	}
	return 0;
}