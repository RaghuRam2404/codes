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
	ll T, N, m, i, temp, w[100010];
	sll(T);
	while(T--){
		sll(N);
		for(i=0; i<N; i++)	sll(w[i]);
		m = w[N-1];
		for(i=N-2; i>=0; i--){
			m++;
			if(m<w[i]) m = w[i];
		}
		pll(m);
	}
	return 0;
}