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
	//freopen("input.in", "r", stdin);
	ll T, N, temp, one, two, i;
	sll(T);
	while(T--){
		sll(N);
		one = two = 0;
		for(i=0; i<N; i++){
			sll(temp); 
			if(temp == 0 || temp == 1) one ++;
			if(temp == 2) two ++;
		}
		//ll ans = (ll)((N*(N-1)/2)-(two*(two-1)/2)-((one*(one-1)/2)+(N-one)*one));
		pll(((N*(N-1)/2)-(two*(two-1)/2)-((one*(one-1)/2)+(N-one)*one)));
	}
	return 0;
}