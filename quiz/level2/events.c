#include <stdio.h>

/**
	EVENTS WILL BE IN A SINGLE DAY
	DAY START FROM 00 : 00 AM TO 11 : 59 PM
	ONE EVENT IS ATLEAST A MIN LONG
**/

void printDetails(int c, int start, int end){
	printf("\tfrom %d:%d %s to ", (start/100>12)?(start/100-12):start/100, start%100, ((start/100>=12)?"PM":"AM"));
	printf("%d:%d %s \n", (end/100>12)?(end/100-12):end/100, end%100, (end/100>=12)?"PM":"AM");	
}

int compare(int ind, int curPos, int events[10][100], int canBook[10][100]){
	int i, st, et;
	int startTime = events[ind][curPos];
	int endTime = events[ind][curPos+1];
	for(i=0; i<curPos; i+=2){
		if(!(canBook[ind][i] && canBook[ind][i+1])) continue;
		st = events[ind][i];
		et = events[ind][i+1];
		if(((startTime<st&&endTime<=st) || (startTime>=et&&endTime>et)));
		else return 0;
	}
	return 1;
}

int main(){
	int i, j, people, ind, starth, startm, endh, endm, eventsC;
	int allowed[100], notAllowed[100], hasEvents[11];
	char std[2], startt[2], endt[2];
	int events[10][100], canBook[10][100], eventCount[10];
	freopen("input.in", "r", stdin);
	
	memset(eventCount, 0, sizeof(eventCount));
	memset(allowed, -1, sizeof(allowed));
	memset(notAllowed, -1, sizeof(notAllowed));
	memset(hasEvents, 0, sizeof(hasEvents));
	memset(canBook, 0, sizeof(canBook));

	scanf("%d%d", &people, &eventsC);
	for(i=0; i<eventsC; i++){
		scanf("%d %d %d %s %d %d %s", &ind, &starth, &startm, startt, &endh, &endm, endt);
		if(strcmp(startt, "AM")!=0 && starth!=12) starth+=12;
		if(strcmp(endt, "AM")!=0 && endh!=12) endh+=12; 
		events[ind][eventCount[ind]] = starth*100+startm;
		events[ind][eventCount[ind]+1] = endh*100+endm;
		eventCount[ind]+=2;
		hasEvents[ind] = 1;
	}

	for(i=0; i<11; i++){
		if(hasEvents[i]){
			printf("FOR GUEST : %d\n", i);
			for(j=0; j<eventCount[i]; j+=2){
				if(j==0){
					printf("\tALLOWED : ");
					printDetails(i, events[i][j], events[i][j+1]);
					canBook[i][j] = 1;
					canBook[i][j+1] = 1;
				}else{
					if(compare(i, j, events, canBook)==1){
						printf("\tALLOWED : ");
						printDetails(i, events[i][j], events[i][j+1]);
						canBook[i][j] = 1;
						canBook[i][j+1] = 1;
					}else{
						printf("\tNOT ALLOWED : ");
						printDetails(i, events[i][j], events[i][j+1]);
						canBook[i][j] = 0;
						canBook[i][j+1] = 0;
					}
				}
			}
			printf("\n");
		}
	}

}