#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct team {
	char name[32], lwr[32];
	int points, goalsSc, goalsLost, won, lost, draw, games, goalDiff;
}T[32];
int compare(const void *p1, const void *p2){
	struct team *p = (struct team *)p1, *q = (struct team *)p2;
	if (p->points != q->points) return (p->points > q->points) ? -1 : 1;
	if (p->won != q->won) return (p->won > q->won) ? -1 : 1;
	if (p->goalDiff != q->goalDiff) return (p->goalDiff > q->goalDiff) ? -1 : 1;
	if (p->goalsSc != q->goalsSc) return (p->goalsSc > q->goalsSc) ? -1 : 1;
	if (p->games != q->games) return (p->games < q->games) ? -1 : 1;
	return strcmp(p->lwr, q->lwr);
}
void makeStringLower(char *p){
	for (; *p; p++) *p = tolower(*p);
}
int main(void){
	static char str1[4096], str2[4096], str3[4096];
	int i, m, n, t, x, y, gx, gy;

	while (scanf("%[^\n]\n", str1) && sscanf(str1, "%d", &t) != 1);

	while (t-- > 0 && scanf("%[^\n]\n", str1)){
		printf("%s\n", str1);
		while (scanf("%[^\n]\n", str1) && sscanf(str1, "%d", &n) != 1);
		memset(T, 0, sizeof(T));
		for (i = 0; i < n; i++) {
			scanf("%[^\n]\n", T[i].name);
			strcpy(T[i].lwr, T[i].name);
			makeStringLower(T[i].lwr);
		}
		while (scanf("%[^\n]\n", str1) && sscanf(str1, "%d", &m) != 1);
		while (m-- > 0 && fgets(str1,sizeof(str1),stdin) != NULL) {
			sscanf(str1, "%[^#]#%d@%d#%[^#\r\n]", str2, &gx, &gy, str3);
			for (x = 0; x < n && strcmp(T[x].name, str2) != 0; x++);
			if (x >= n){
				makeStringLower(str2);
				for (x = 0; x < n && strcmp(T[x].lwr, str2) != 0; x++);
			}
			for (y = 0; y < n && strcmp(T[y].name, str3) != 0; y++);
			if (y >= n){
				makeStringLower(str3);
				for (y = 0; y < n && strcmp(T[y].lwr, str3) != 0; y++);
			}
			T[x].goalsSc += gx;
			T[x].goalsLost += gy;
			T[y].goalsSc += gy;
			T[y].goalsLost += gx;
			T[x].games++;
			T[y].games++;
			if (gx > gy){
				T[x].won++;
				T[y].lost++;
			} else if (gx == gy){
				T[x].draw++;
				T[y].draw++;
			} else {
				T[x].lost++;
				T[y].won++;
			}
		}
		for (i = 0; i < n; i++) T[i].points = 3 * T[i].won + T[i].draw;
		for (i = 0; i < n; i++) T[i].goalDiff = T[i].goalsSc - T[i].goalsLost;
		qsort(T, n, sizeof(T[0]), &compare);
		for (i = 0; i < n; i++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				i + 1, T[i].name, T[i].points,
				T[i].games, T[i].won, T[i].draw,
				T[i].lost, T[i].goalDiff,
				T[i].goalsSc, T[i].goalsLost);
		}
		if (t > 0) printf("\n");
	}

	return 0;
