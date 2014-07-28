#include <bits/stdc++.h>
using namespace std;

int gcd ( int a, int b ) { int c; while ( a != 0 ) { c = a; a = b%a; b = c; } return b; }

int winner(int a, int b){
	if(b==1) return 1;
	if(a==1) return 2;
	int turn = 0;
	while(a!=1 && b!=1 && (a!=0 && b!=0) ){
		int g;
		if(turn == 0){
			g = gcd(a,b);
			if(g>1){
				if(b%g==0) b/=g;
				else b--;
			}else if(g==1){
				b--;
			}
			turn = 1;
		}else{
			g = gcd(b,a);
			if(g>1){
				if(a%g==0) a/=g;
				else a--;
			}else if(g==1){
				a--;
			}
			turn = 0;
		}
	}
	if(a<=0 || b<=0) return 0;
	if(a==1) return 2;
	if(b==1) return 1;
}

int main(){
	int i, j;
	//freopen("input.in", "r", stdin);
	//freopen("output", "w", stdout);
	//cout<<winner(2,3)<<endl;
	//return 0;
	/*for(i=1; i<=1000; i++){
		for(j=1; j<=1000; j++){
			cout<<i<<" "<<j<<" "<<winner(i,j)<<"\n";
		}
	}*/
	int n, a, b;
	cin>>n;
	while(n--){
		cin>>a>>b;
		int w = winner(a,b);
		if(w == 1){
			cout<<"Arjit\n";
		}else if(w==2)
			cout<<"Chandu Don\n";
		else if(w==0)
			cout<<"Draw\n";
	}
}