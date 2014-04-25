#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b)==2 && a!=-1 && b!=-1){
		if(a==0 && b==0) cout<<0<<endl;
		else if(a==b) cout<<1<<endl;
		else cout<<((a+b)/(min(a,b)+1))<<endl;
	}
	return 0;
}