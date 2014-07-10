#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.in", "r", stdin);
	int t, n, i, temp, j, count, maxP, timear[1001];
	vector<pair<int, int> >vp;
	pair<int, int> p;
	cin>>t;
	while(t--){
		cin>>n;
		memset(timear, 0, sizeof(timear));
		for(i=0; i<n; i++){
			cin>>temp;
			timear[temp] ++;
		}
		for(i=0; i<n; i++){
			cin>>temp;
			timear[temp] --;
		}
		count = 0;
		maxP = 0;
		for(i=0; i<1001; i++){
			count += timear[i];
			if(count>maxP) maxP = count;
		}
		cout<<maxP<<endl;
	}
	return 0;
}