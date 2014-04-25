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

int H, W;
char map[25][25];
bool visited[25][25];

int dfs(int posX, int posY){
	if(posX > 0 && posX < W && posY > 0 && posY < H){
		if(map[posX][posY] == '@' || map[posX][posY] == '.'){
			return dfs(posX+1, posY)+dfs(posX-1, posY)+dfs(posX, posY+1)+dfs(posX, posY-1);
		}
	}
	return 0;
}

int main(){
	int N, i, j, posX, posY;
	string row;
	s(N);
	while(N--){
		s(W), s(H);
		bool found = false;
		memset(visited, false, sizeof(visited));
		for(i=0; i<H; i++){
			cin>>map[i];
			for(j=0; j<W && !found; j++){
				if(map[i][j] == '@') posX = j, posY = i, found = true;
			}
		}
		p(dfs(posX, posY));
	}
	return 0;
}