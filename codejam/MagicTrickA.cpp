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
	int i,t,n1,n2,j,k;
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	int a1[4][4], a2[4][4];
	s(t);
	for(i=1; i<=t; i++){
		s(n1);
		for(j=0; j<4; j++){
			for(k=0; k<4; k++)
				s(a1[j][k]);
		}
		s(n2);
		for(j=0; j<4; j++){
			for(k=0; k<4; k++)
				s(a2[j][k]);
		}
		map<int, int> m;
		for(j=0; j<4; j++){
			m[a1[n1-1][j]] = 100;
		}
		int cnt = 0, ans=-1;
		for(j=0; j<4; j++){
			if(m[a2[n2-1][j]] == 100)
				cnt++, ans=a2[n2-1][j];
		}
		if(cnt == 0){
			cout<<"Case #"<<i<<": "<<"Volunteer cheated!"<<endl;
		}else if(cnt > 1){
			cout<<"Case #"<<i<<": "<<"Bad magician!"<<endl;
		}else if(cnt == 1){
			cout<<"Case #"<<i<<": "<<ans<<endl;
		}

	}
	return 0;
}