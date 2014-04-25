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
	int t;
	s(t);
	while(t--){
		ull x,y,z;
		ull term,d,a,n;
		ss(x), ss(y), ss(z);
		n = (2*z)/(x+y);
		d = (y-x)/(n-5);
		a = (x-2*d);
		term = a;
		pp(n);
		for(int i=0; i<n; i++){
			printf("%llu ", term);
			term += d;
		}
		printf("\n");
	}
	return 0;
}