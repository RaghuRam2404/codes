#include <stdio.h>

int typeOfFriends(int **a, int p1, int p2, int n){
	int i, j;
	if(a[p1-1][p2-1]==1 || a[p2-1][p1-1]==1) return 1;
	// check friends of p1
	for(i=0; i<n; i++){
		if(a[p1-1][i] != 0){
			for(j=0; j<n; j++){
				if(a[i][j]==1 && j==p2-1) return 2;
			}
		}
	}
	return 0;
}

int main(){
	int n, **a, i, j, rel, p1, p2, answer;
	printf("No of people : ");
	scanf("%d", &n);
	a = malloc(sizeof(int*)*n);
	for(i=0; i<n; i++)
		a[i] = malloc(sizeof(int)*n);

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			a[i][j] = 0;

	printf("No of relation ships : ");
	scanf("%d", &rel);

	for(i=0; i<rel; i++){
		scanf("%d %d", &p1, &p2);
		a[p1-1][p2-1] = 1;
		a[p2-1][p1-1] = 1;
	}

	printf("No of test cases : ");
	scanf("%d", &rel);

	// by rule 1
	/*for(i=0; i<rel; i++){
		printf("Please enter two person's number : ");
		scanf("%d %d", &p1, &p2);
		printf("%d and %d are %s friends\n", p1, p2, (a[p1-1][p2-1]==1 || a[p2-1][p1-1]==1)?"direct":"non direct");
	}*/

	for (i=0; i<rel; i++){
		printf("Please enter two person's number : ");
		scanf("%d %d", &p1, &p2);
		answer = typeOfFriends(a, p1, p2, n);
		switch(answer){
			case 1:
				printf("%d and %d are %s friends\n", p1, p2, "direct");
				break;
			case 2:
				printf("%d and %d are %s friends\n", p1, p2, "level 1");
				break;
			case 0:
				printf("%d and %d are %s friends\n", p1, p2, "not");
				break;
		}
	}

}