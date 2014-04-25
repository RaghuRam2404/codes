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

bool fits(ull a, ull b, ull p, ull q){
	ull t;
	if(a<b){ t=a; a=b; b=t; }
	if(p<q){ t=p; p=q; q=t; }

	if( a > p && b > q ) return true;
	if( q >= b ) return false;
	double x, y, L, K, D;
	if( p*p+q*q < b*b ) return true;
	if( p*p+q*q > a*a+b*b ) return false;
	L = ( b - sqrt(p*p + q*q - a*a) ) / 2.0;
	K = ( a - sqrt(p*p + q*q - b*b) ) / 2.0;
	D = q;
	if( D*D > L*L + K*K ) return false;
	return true;
}

int main(){
	ull a,b,x,y,n;
	ss(n);
	while(n--){
		ss(a), ss(b), ss(x), ss(y);
		if(fits(a,b,x,y)) printf("Escape is possible.\n");
		else printf("Box cannot be dropped.\n");
	}
	return 0;
}
