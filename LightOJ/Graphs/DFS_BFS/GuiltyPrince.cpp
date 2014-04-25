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
char positionMap[25][25];
bool visited[25][25];

int dfs(int posX, int posY){
	if(posX >= 0 && posX < H && posY >= 0 && posY < W){
		if((positionMap[posX][posY] == '@' || positionMap[posX][posY] == '.') && !visited[posX][posY]){
			visited[posX][posY] = true;
			return (dfs(posX+1, posY)+dfs(posX-1, posY)+dfs(posX, posY+1)+dfs(posX, posY-1)+1);
		}
	}
	return 0;
}

int main(){
	//freopen("input.in", "r", stdin);
	int N, i, j, posX, posY;
	string row;
	s(N);
	for(int test=1; test<=N; test++){
		s(W), s(H);
		bool found = false;
		memset(visited, false, sizeof(visited));
		for(i=0; i<H; i++){
			cin>>positionMap[i];
			for(j=0; j<W && !found; j++){
				if(positionMap[i][j] == '@') posX = i, posY = j, found = true;
			}
		}
		cout<<"Case "<<test<<": "<<dfs(posX, posY)<<endl;
	}
	return 0;
}