#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
#define sll(a) scanf("%lld", &a)
#define pll(a) printf("%lld\n", a)
#define ss(a) scanf("%llu", &a)
#define pp(a) printf("%llu\n", a)
#define sstring(a) scanf("%s", a)

int main(){
	int N, a[100005];
	int i;
	vector<int> neg;

	while(s(N)==1 && N!=0){
		neg.clear();
		int count = 0;
		for(i=0; i<N; i++){
			s(a[i]);
			if(a[i]<0)
				neg.push_back(i);
			if(a[i]==0)
				count++;
		}
		for(i=0; i<neg.size(); i++){
			int ind = neg[i], j=1;
			// get the nearest index
			while(a[ind]==0){
				int c=ind, d=ind;
				if(ind+j<N) c=ind+j;
				if(ind-j>=0) d=ind-j;

				if()

			}
		}
	}
	return 0;
}