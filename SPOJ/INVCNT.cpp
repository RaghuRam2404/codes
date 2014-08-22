#include <bits/stdc++.h>
using namespace std;

#define max 200005
#define s(a) scanf("%d", &a)
int bit[10000008];
int m=-1;

void add(int x, int v){
	if(m<x) m=x;
	for(int i=x; i<=max; i+=(i&-i)){
		bit[i] += v;
	}
}

int sum(int x){
	int s = 0;
	for(int i=x; i>0; i-=(i&-i)){
		s += bit[i];
	}
	return s;
}

int main(){
	int t, n, i, x;
	freopen("input.in", "r", stdin);
	memset(bit, 0, sizeof(bit));
	s(t);
	while(t--){
		int total = 0;
		m = -1;
		memset(bit, 0, sizeof(bit));
		s(n);
		for(i=0; i<n; i++){
			s(x);
			add(x, 1);
			if(x != m)
				total += (sum(m)-sum(x));
		}
		cout<<total<<endl;
	}
	return 0;
}
