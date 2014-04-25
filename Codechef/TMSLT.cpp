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
	freopen("input2.in", "r", stdin);
	int T, N, a, b, c, d, i, mod = 1000000;
	s(T);
	while(T--){
		ll teamA=0, teamB=0, prev=d;
		s(N), s(a), s(b), s(c), s(d);
		if(N%2==0){
			// s0 = d will be taken by teamB
			teamB = d;
			for(i=1; i<N; i++){
				cout<<prev<<" ";
				prev = (a*prev*prev + b*prev + c)%mod;
				if(i%2==1) teamA += prev;
				else	teamB += prev;
			}cout<<prev<<endl;

		}else{
			// s0 = d will be taken by teamA
			teamA = d;
			for(i=1; i<N; i++){
				cout<<prev<<" ";
				prev = (a*prev*prev + b*prev + c)%mod;
				if(i%2==0) teamA += prev;
				else	teamB += prev;
			}cout<<prev<<"\n";

		}
		pll(abs(teamA-teamB));
	}
	return 0;
}