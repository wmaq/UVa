//Obscure sorting program by wmaq
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int logar;

/*Header*/
void swap(int* table, int x, int y);
void bubbleSort(int *table, int len);
void quickSort(int *table, int first, int last, int depth);
void heapSort(int *table, int len);
/*Main*/
int main(void)
	{
		int size;
		int *num;
		int i,j;

		printf("Podaj rozmiar tablicy: ");
		scanf("%d",&size);

		num=malloc((size+10)*sizeof(int));

		logar = log2 (size);

		srand(time(0));
		printf("\nRandomized table:\n");
		for(i=0;i<size;i++){
			num[i] = rand() % 1000;
			printf("%d ",num[i]);
		}
		quickSort(num,0,size-1,0);
		printf("\n\nhybridSort output:\n");
		for(i=0;i<size;i++){
			printf("%d ", num[i]);
		}
		printf("\n");
		free(num);
		return 0;
	}

/*Functions*/
void swap(int* table, int x, int y)
	{
		int z=table[x];
		table[x]=table[y];
		table[y]=z;
		return;
}
void quickSort(int *table, int first, int last, int depth)
	{
		int pos,temp;
		int i,j;

		pos=(first+last)/2;
		temp=table[pos];

		if(first>=last) return;
		else if((last - first)<4){
			printf("BUBBLE\n");
			bubbleSort(table+first,(last-first)+1);
		} else if(depth>logar) {
			printf("HEAP\n");
			heapSort(table+first,(last-first)+1);
		} else {
			printf("QUICK\n");
		swap(table,pos,last);

		for(i=j=first; i<last ; i++){

			if(table[i] < temp){
				swap(table,i,j);
				j++;
			}
		}
		swap(table,j,last);

		quickSort(table, first, j,depth+1);
		quickSort(table, j+1, last,depth+1);
		}
	}
void bubbleSort(int *table, int len)
	{
		int i,j,temp;
		for(i=0; i<(len-1); i++){
			for(j=0; j < (len-1)-i; j++){
				if(table[j] > table[j+1]){
					temp = table[j+1];
					table[j+1] = table[j];
					table[j] = temp;
				}
			}
		}
		return;
	}
void heapSort(int *table, int len)
	{
		if(len==0) return;
		int temp;
		int main, par, ch, pos;
		main = len;
		par = len/2;
		while(len){
			if(par>0){
				temp = table[--par];
			} else {
				main--;
				if(main==0) return;
				temp = table[main];
				table[main] = table[0];
			}
			pos = par;
			ch = (pos*2)+1;
			while(ch<main) {
				if(ch + 1 < main && table[ch+1] > table[ch]){
					ch++;
				}
				if(table[ch] > temp){
					table[pos] = table[ch];
					pos = ch;
					ch = (pos*2)+1;
				} else {
					break;
				}
			}
			table[pos]=temp;
		}
	}