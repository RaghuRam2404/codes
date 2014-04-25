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
	int T, N, m, mi, i, temp;
	int w[100010];
	s(T);
	while(T--){
		s(N);
		m = -1;
		for(i=0; i<N; i++){
			s(temp);
			if(temp>m) m = temp, mi = i;
		}
		p(mi+m);
	}
	return 0;
}