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

// function returns no of cells i need to have one click
int findAvailCells(int r, int c, int m){
	if(r==1 && c==1){
		return m;
	}else if(r==1 || c==1){
		return 2+m;
	}else{
		return m+4;
	}
}

int main(){
	int t, r, c, i, j, k, m;
	char grid[51][51] = {0};
	//freopen("C-small-attempt3.in", "r", stdin);
	//freopen("C-small-attempt3.out", "w", stdout);
	s(t);
	for(int test=1; test<=t; test++){
		s(r),s(c), s(m);
		if(r==c && r==1){
			printf("Case #%d:\n",test);
			if(m==0) printf("c\n");
			else printf("Impossible\n");
			continue;
		}
		if(findAvailCells(r,c,m) > r*c){
			printf("Case #%d:\nImpossible\n",test);
		}else{
			memset(grid, '.', sizeof(grid));
			grid[0][0] = 'c';
			int cnt = 0;
			bool over = false;
			for(j=r-1; j>=2 && !over; j--){
				for(k=c-1; k>=0 && !over; k--){
					if(cnt >= m){
						over = true;
						break;
					}grid[j][k] = '*';
					cnt++;
				}
			}
			for(j=c-1; j>=0 && !over; j--){
				if(cnt >= m){
					over = true;
					break;
				}
				if(r>1)
					grid[1][j] = '*';
				else{
					grid[0][j] = '*';
					cnt++;
					continue;
				}
				cnt++;
				if(cnt >= m){
					over = true;
					break;
				}
				grid[0][j] = '*';
				cnt++;
			}
			printf("Case #%d:\n",test);
			for(j=0; j<r; j++){
				for(k=0; k<c; k++)
					cout<<grid[j][k];
				cout<<endl;
			}
		}
	}
	return 0;
}