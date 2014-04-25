#include <bits/stdc++.h>
using namespace std;

int main(){
	int i, j;
	char target[10], guess[10];
	scanf("%s%s",target,guess); 
	int c=0,d=0; 
	for(i=0;i<6;i++) {
		if(guess[i]==target[i]) 
		c++; 
	}
	for(i=0;i<6;i++) { 
		for(j=0;j<6;j++){ 
			if(guess[i]==target[j] && i!=j) 
			d++; 
		}
	}
	printf("%dA%dB\n",c,d);
	return 0;
}