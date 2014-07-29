#include <bits/stdc++.h>
using namespace std;

class BishopMove{
	public:
		int howManyMoves(int r1, int c1, int r2, int c2){
			if(r1==r2 && c1==c2) return 0;
			if(abs(r1-r2)==abs(c1-c2)) return 1;
			if(((r1&1 && c1&1) || ((r1&1)==0 && (c1&1)==0)) && ((r2&1 && c2&1) || ((r2&1)==0 && (c2&1)==0))) return 2;
			if(((r1&1 && (c1&1)==0) || ((r1&1)==0 && c1&1)) && ((r2&1 && (c2&1)==0) || ((r2&1)==0 && c2&1))) return 2;
			else return -1;
			
		}
};

int main(){
	BishopMove b;
	cout<<b.howManyMoves(1,2,1,4)<<endl;
}