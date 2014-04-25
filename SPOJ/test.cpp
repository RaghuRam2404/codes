
#define _CRT_SECURE_NO_WARNINGS 1
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 100001;

i64 BIT[MAX];
i64 a[MAX];
int root[MAX];

void update(int x, i64 v, int n) {
	while(x <= n) {
		BIT[x] += v;
		x += (x & -x);
	}
}

i64 readsum(int x) {
	i64 ret = 0;
	while(x > 0) {
		ret += BIT[x];
		x -= (x & -x);
	}
	return ret;
}

int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}

void modify(int x, int y, int n) {
	int i = find(x);
	while(x <= i && i <= y) {
		if(a[i] != 1) {
			update(i, -a[i], n);
			a[i] = (i64)floor(sqrt((double)a[i]));
			update(i, a[i], n);
			if(a[i] == 1) root[i] = i + 1;
		}
		i = find(i + 1);
	}
}

int main() {
	READ("input.in");
	//WRITE("out.txt");
	int n, q, i, x, y, t, cs;
	for(cs = 1; scanf("%d", &n) == 1; cs++) {
		CLR(BIT);
		for(i = 1; i <= n; i++) {
			scanf("%lld", a + i);
			update(i, a[i], n);
			root[i] = i;
		}
		printf("Case #%d:\n", cs);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d %d", &t, &x, &y);
			if(x > y) swap(x, y);
			if(t) printf("%lld\n", readsum(y) - readsum(x-1));
			else modify(x, y, n);
		}
		printf("\n");
	}
	return 0;
}

/*#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf (1ull<<63)-1
#define N 100005
#define maxn 100005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define ULL unsigned long long
#define lson (step<<1)
#define rson (step<<1|1)
#define MOD 1000000007
#define mp(a,b) make_pair(a,b)
using namespace std;
struct Node{
	int left,right;
	LL sum;
}L[N*5];
int n,q;
LL a[N];
void Push_Up(int step){
	L[step].sum=L[lson].sum+L[rson].sum;
}
void Bulid(int step,int l,int r){
	L[step].left=l;L[step].right=r;
	if(l==r) {L[step].sum=a[l];return ;}
	int m=(l+r)/2;
	Bulid(lson,l,m);
	Bulid(rson,m+1,r);
	Push_Up(step);
}
void Update(int step,int l,int r){
	cout<<"=>"<<L[step].left<<" "<<L[step].right<<" "<<L[step].sum<<endl;
	if(L[step].right-L[step].left+1==L[step].sum) return;
	if(L[step].left==L[step].right){
		L[step].sum=(LL)sqrt(L[step].sum+0.0);
		return;
	}
	int m=(L[step].left+L[step].right)/2;
	if(r<=m) Update(lson,l,r);
	else if(l>m) Update(rson,l,r);
	else{
		Update(lson,l,m);
		Update(rson,m+1,r);
	}
	Push_Up(step);
}
LL Query(int step,int l,int r){
	if(L[step].left==l&&L[step].right==r)
		return L[step].sum;
	int m=(L[step].left+L[step].right)/2;
	if(r<=m) return Query(lson,l,r);
	else if(l>m) return Query(rson,l,r);
	else return Query(lson,l,m)+Query(rson,m+1,r);
}
int main(){
	freopen("input.in", "r", stdin);
	int cas=0;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		Bulid(1,1,n);
		scanf("%d",&q);
		printf("Case #%d:\n",++cas);
		while(q--){
			int k,l,r;
			scanf("%d%d%d",&k,&l,&r);
			if(l>r) swap(l,r);
			if(k==0) Update(1,l,r);
			else printf("%lld\n",Query(1,l,r));
		}
		printf("\n");
	}
	return 0;
}
*/