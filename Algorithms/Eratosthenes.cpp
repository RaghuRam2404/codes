#include <bits/stdc++.h>
using namespace std;

vector<bool> EratosthenesPrimes(long n){
	vector<bool> v;
	int i;
	for(i=1; i<=n+1; i++) v.push_back(true);
	int sq = sqrt(n);
	v[0] = false;
	v[1] = false;
	for(i=2; i<=sq; i++)
		if(v[i] == true)
			for(int j=i*2; j<=n; j+=i)
				v[j] = false;
	return v;
}

int main(){
	vector<bool> v = EratosthenesPrimes(10000);
	for(int i=0; i<v.size(); i++)
		if(v[i])
			cout<<i<<",";
	cout<<endl;
}