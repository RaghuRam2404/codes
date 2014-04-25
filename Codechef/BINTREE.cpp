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

ll count(ll a, ll b){
	list<int> aa, bb;
	while(a){
		aa.push_front(a&1);
		a >>= 1;
	}
	while(b){
		bb.push_front(b&1);
		b >>= 1;
	}
	list<int>::iterator it, it2; 
	int count = 0;
	for(it=aa.begin(), it2=bb.begin(); it!=aa.end() && it2!=bb.end(); ++it, ++it2){
		if(*it == *it2)
			count++;
		else break;
	}
	return (aa.size()+bb.size()-count-count);
}

int main(){
	freopen("input.in", "r", stdin);
	ll N, from, to;
	sll(N);
	while(N--){
		sll(from), sll(to);
		pll(count(from, to));
	}
	return 0;
}