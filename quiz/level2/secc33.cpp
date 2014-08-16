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

void printLevelOnly(int lno){
	int d[100],size=0;
	while(lno){
		d[size++] = lno%10;
		lno /= 10;
	}
	for(int i=size-1; i>=0; i--){
		cout<<d[i]<<((i!=0)?".":"");
	}cout<<" : ";
}

void printLevels(char s[1000], char states[1000], int lno, int from, int to){
	int i,t,c=0,start;
	char st='\0';
	int br = 0;
	if(states[from]=='O'){
		printLevelOnly(lno);
		for(i=from; i<=to; i++)
			cout<<s[i];
		cout<<endl;
		if(from+1<=to && states[from+1]=='O'){
			for(i=from+1; i<=to-1; i++){
				if(states[i]=='O' && br==0){
					start = i;
					br = 1;
					//cout<<i<<","<<br<<" ";
				}else if(states[i]=='O' && br>0){
					br++;
				}else if(states[i]=='C' && br>1){
					br--;
				}
				else if(states[i]=='C' && br==1){
					br --;
					t = lno+1;
					c++;
					printLevels(s,states,lno*10+c,start,i);
				}
			}
		}else{
			printLevels(s,states,lno,from+1,to-1);	
		}
	}else{
		int count = 1;
		for(i=from; i<=to; i++){
			if(states[i] == 'Q' && st!='Q'){
				st = 'Q';
				printLevelOnly(lno*10+count);
				count++;
				cout<<s[i];
			}else if(states[i]=='C' && st=='W'){
				cout<<endl;
			}
			else if(states[i]=='Q' && st=='Q'){
				cout<<s[i];
				cout<<endl;
				st = '\0';
			}else if(s[i]=='S' && st=='\0'){
				if(!(states[i+1]=='S' || states[i+1]=='O' || states[i+1] == 'C')){
					count++;
					printLevelOnly(lno*10+count);
				}
			}else if(s[i]=='S' && st=='S'){
				i--;
				st = 'S';
				cout<<endl;
			}else if(st == 'Q' || st == 'S'){cout<<s[i];}
			else if(states[i]=='W' && st=='\0'){
				st='W'; 
				printLevelOnly(lno*10+count);
				cout<<s[i]; 
				count++;
			}else if((states[i]=='S' || states[i]==' ') && st=='W'){
				cout<<endl;
				st = '\0';
				i--;
			}else if(states[i]=='W' && st=='W'){
				cout<<s[i];
			}
		}
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
	int level[100];
	memset(temps, '\0', sizeof(temps));
	gets(s);
	int n = strlen(s);

	for(i=0; i<n; i++){
		if(s[i] == '(') states[i] = 'O';
		else if(s[i] == ')') states[i] = 'C';
		else if(s[i] == '\"' && !(s[i-1]=='@' || s[i-1]=='#' || s[i-1]=='$' || s[i-1]=='%' || s[i-1]=='^' || s[i-1]=='&' || s[i-1]=='*') && (i-1)>=0) states[i] = 'Q';
		else if(s[i] == ' ' && !(s[i-1]=='@' || s[i-1]=='#' || s[i-1]=='$' || s[i-1]=='%' || s[i-1]=='^' || s[i-1]=='&' || s[i-1]=='*') && (i-1)>=0) states[i] = 'S';
		else if(states[i]!='\"') states[i] = 'W';
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
		if(states[i]=='S' && (i+1)<n && (states[i+1]=='C')) states[i]=' ';
		else if(states[i]=='Q' && start=='S'){
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

	printLevels(s, states, 1, 0, n-1);
	cout<<endl;
}