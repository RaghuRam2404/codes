#include <bits/stdc++.h>
using namespace std;
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
	
int main(){
	int n;
	s(n);
	int a[105];
	for(int i=0; i<n; i++){
		s(a[i]);
	}
	sort(a, a+n);
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}