#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)

int main(){
	//freopen("input.in", "r", stdin);
	int n;
	char seq[3005], first, expected;
	s(n);
	cin>>seq;
	int count = 0, interval=0;
	bool firstFound = false;
	for(int i=0; i<n; i++){
		if(!firstFound && seq[i] != '.'){
			if(seq[i] == 'L'){
				first = 'L';
				count = 0;
				expected = 'R';
			}else{
				first = 'R';
				expected = 'L';
			}
			firstFound = true;
		}else if(!firstFound && seq[i] == '.'){
			count ++;
		}

		// no search for intervals
		if(firstFound && seq[i]!=expected){
			interval++;
		}else if(firstFound && seq[i]==expected){
			interval++;
			if(interval%2!=0) count++;
			expected = (expected=='L')?'R':'L';
			interval = 0;
		}
	}
	if(expected == 'R')
		count += interval-1;
	p(count);
	return 0;
}