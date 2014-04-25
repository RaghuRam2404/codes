// author : raghuram2404
// string manipulation
// accepted for 77.58

#include <bits/stdc++.h>
using namespace std;

class FoxAndGomoku{
public:
	string win(vector <string> b){
		int n = b.size();
		for(int i=0; i<=n-1; i++){
			for(int j=0; j<=n-1; j++){
				if(i<=n-5)
					if(b[i][j]=='o' && b[i+1][j]=='o' && b[i+2][j]=='o' && b[i+3][j]=='o' && b[i+4][j]=='o') return "found";
				if(j<=n-5)
					if(b[i][j]=='o' && b[i][j+1]=='o' && b[i][j+2]=='o' && b[i][j+3]=='o' && b[i][j+4]=='o') return "found";
				if(i<=n-5 && j<=n-5)
					if(b[i][j]=='o' && b[i+1][j+1]=='o' && b[i+2][j+2]=='o' && b[i+3][j+3]=='o' && b[i+4][j+4]=='o') return "found";

			}
		}
		for(int i=0; i<=n-5; i++){
			for(int j=n-1; j>=4; j--){
				if(b[i][j]=='o' && b[i+1][j-1]=='o' && b[i+2][j-2]=='o' && b[i+3][j-3]=='o' && b[i+4][j-4]=='o') return "found";
			}
		}
		return "not found";
	}
};

int main(){

	FoxAndGomoku f;
	std::vector<string> v;
	v.push_back("..o.oo");
	v.push_back(".o.ooo");
	v.push_back(".oo..o");
	v.push_back("o..ooo");
	v.push_back("o..o.o");
	v.push_back("oo...o");
	cout<<f.win(v)<<endl;
	v.clear();
	// {"....o", "...o.", "..o..", ".o...", "o...."}
	v.push_back("....o");
	v.push_back("...o.");
	v.push_back("..o..");
	v.push_back(".o...");
	v.push_back("o....");
	cout<<f.win(v)<<endl;
	return 0;
}