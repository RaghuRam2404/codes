// author : raghuram2404
// string ad-hoc
// accepted for 219.16 points

#include <bits/stdc++.h>
using namespace std;

class ErasingCharacters{
	public:
		string simulate(string s){
			int i;
			while(true){
				i=-1;
				int n = s.length();
				for(int j=0; j<=n-2; j++)
					if(s[j] == s[j+1]){
						i = j; break;
					}
				if(i==-1) break;
				s.erase(i,2);
			}
			return s;
		}
};

int main(){
	ErasingCharacters e;
	cout<<e.simulate("cieeilll")<<endl;
	return 0;
}