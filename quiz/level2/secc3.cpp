#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.in", "r", stdin);
	int i, count =0, print = 0;
	char expected='\0';
	char s[1000];
	char temps[1000];
	memset(temps, '\0', sizeof(temps));
	gets(s);

	for(i=0; i<strlen(s); i++){
		if(s[i] == '(' || s[i] == ')' || (s[i] == ' ' && expected!='\"'));
		else temps[count] = s[i],count++;
		if(s[i] == '\"' && expected=='\"'){
			temps[count]='\0';
			count = 0;
			expected = '\0';
			print = 1;
		}else if(s[i]==' ' && expected==' '){
			temps[count]='\0';
			print = 1;
			count = 0;
			expected = '\0';
		}else if(s[i]==' ' && expected=='\0'){
			expected = ' ';
		}else if(s[i]=='\"' && (expected==' ' || expected=='\0')){
			expected='\"';
			temps[0] = s[i];
			count = 1;
		}
		if(count==0 && print){
			print=0;
			cout<<temps<<endl;
		}
	}

}