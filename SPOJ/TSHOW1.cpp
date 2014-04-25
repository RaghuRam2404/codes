#include <bits/stdc++.h>
using namespace std;

void print(long long a){
	vector<int> v;
	while(a!=1){
		v.push_back(a&1);
		a = a>>1;
	}
	for(int i=v.size()-1; i>=0; i--){
		if(v[i] == 0) cout<<5;
		else cout<<6;
	}
	cout<<endl;
}

int main(){
	freopen("input.in", "r", stdin);
	long long n, k;
	cin>>n;
	while(n--){
		cin>>k;
		print(k+1);
	}
}
