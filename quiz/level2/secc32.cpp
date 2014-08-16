#include <bits/stdc++.h>
using namespace std;

void sortBasedOnRange(int ranges[100][2], int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(ranges[i][0] > ranges[j][0]){
				int temp = ranges[i][0];
				ranges[i][0] = ranges[j][0];
				ranges[j][0] = temp;
				temp = ranges[i][1];
				ranges[i][1] = ranges[j][1];
				ranges[j][1] = temp;
			}
		}
	}
}

void printas(char s[1000], int from, int to){
	for(; from<=to; from++){
		cout<<s[from];
	}
}

int main(){
	freopen("input.in", "r", stdin);
	int i, count =0, print = 0;
	char expected='\0';
	char s[1000];
	char states[1000];
	char temps[1000];
	int ranges[100][2];
	memset(temps, '\0', sizeof(temps));
	gets(s);
	int n = strlen(s);

	for(i=0; i<n; i++){
		if(s[i] == '(') states[i] = 'O';
		else if(s[i] == ')') states[i] = 'C';
		else if(s[i] == '\"' && !(s[i-1]=='@' || s[i-1]=='#' || s[i-1]=='$' || s[i-1]=='%' || s[i-1]=='^' || s[i-1]=='&' || s[i-1]=='*') && (i-1)>=0) states[i] = 'Q';
		else if(s[i] == ' ' && !(s[i-1]=='@' || s[i-1]=='#' || s[i-1]=='$' || s[i-1]=='%' || s[i-1]=='^' || s[i-1]=='&' || s[i-1]=='*') && (i-1)>=0) states[i] = 'S';
		else states[i] = ' ';
	}
	states[i] = '\0';
	cout<<states<<endl;

	char start = '\0';
	expected='\0';
	int from, to, a=0;
	for(i=0; i<n; i++){
		if(states[i] == 'Q' && start!='Q'){
			start = 'Q';
			from = i;
		}else if((states[i]=='Q' || states[i]=='C') && start=='Q'){
			to = i;
			start = '\0';
			ranges[a][0] = from;
			ranges[a][1] = to;
			a++;
		}else if(states[i] == 'S' && start == 'Q'){
			states[i] = ' ';
		}
	}
	cout<<states<<endl;

	start = '\0';
	for(i=0; i<n; i++){
		if(states[i]=='Q' && start=='S'){
			start = '\0'; states[from] = ' ';
		}else if(states[i]=='S' && start=='\0'){
			from = i; start='S';
		}else if(states[i]=='S' && start=='S'){
			to = i; i--; start='\0';
			ranges[a][0] = from+1;
			ranges[a][1] = to-1;
			a++;
		}else if(states[i]=='W' && start=='\0'){
			from = i; start='W';
		}else if((states[i]=='S' || states[i]=='C') && start=='W'){
			to = i-1;
			start='\0';
			ranges[a][0] = from;
			ranges[a][1] = to-1;
			a++;
			if(states[i]=='S') i--;
		}
	}

	cout<<states<<endl;
	sortBasedOnRange(ranges, a);
	for(i=0; i<a; i++){
		cout<<(i+1)<<" : ";
		printas(s, ranges[i][0], ranges[i][1]);
		cout<<endl;
	}

}