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
	int n, m, i, j, digit, x;
	int details[100010];
	int count[11] = {0};
	char a[100010];
	s(n), s(m);
	cin>>a;
	memset(details, 0, sizeof(details));
	for(i=0; i<n; i++){
		digit = int(a[i])%48;
		count[digit]++;
		details[i] = 0;
		if(i==0){
			details[i] = digit;
			continue;
		}
		for(j=0; j<10; j++){
			if(digit != j)
				details[i] += abs(count[j]*(j - digit));
		}
	}
	for(i=0; i<m; i++){
		s(x); --x;
		if(x==0) p(0);
		else p(details[x]);
	}
	return 0;
}