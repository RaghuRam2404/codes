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
	long double x, c, f, cf;
	cout.precision(7);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t;
	s(t);
	for(int i=1; i<=t; i++){
		cin>>c>>f>>x;
		cf = 2;
		long double timeTaken = 0;
		while(true){
			if( ((long double)(c/cf)+(long double)(x/(cf+f)))  <  ((long double)(x/cf)) ){
				timeTaken += (long double)(c/cf);
				cf += f;
			}else{
				timeTaken += (long double)(x/cf);
				break;
			}
		}
		printf("Case #%d: %.7Lf\n",i,timeTaken);
		//cout<<"Case #"<<i<<": "<<timeTaken<<endl;
	}
	return 0;
}