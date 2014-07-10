#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.in", "r", stdin);
	int t, g, i, n, q;
	cin>>t;
	while(t--){
		cin>>g;
		while(g--){
			cin>>i>>n>>q;
			if(i==q)
				cout<<n/2<<endl;
			else
				cout<<(n-n/2)<<endl;
		}
	}
	return 0;
}