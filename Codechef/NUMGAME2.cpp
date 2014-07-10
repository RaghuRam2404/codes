#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin>>t;
	while(t--){
		cin>>n;
		n--;
		if(n%4) cout<<"BOB"<<endl;
		else cout<<"ALICE"<<endl;
	}
	return 0;
}