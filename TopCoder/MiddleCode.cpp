#include <bits/stdc++.h>
using namespace std;

class MiddleCode{

public:

	string encode(string s){
		string t;
		for(;s.size() != 0;){
			int n = s.size();
			if(n%2 == 0){
				//cout<<"even ";
				// compare middle two
				if(s[(n>>1)-1] > s[(n>>1)]){
					t += s[(n>>1)];
					s.erase((n>>1), 1);
				}else{
					t += s[(n>>1)-1];
					s.erase((n>>1)-1,1);	
				}
			}else{
				//cout<<"odd ";
				t += s[n>>1];
				s.erase((n>>1), 1);
			}
		}
		return t;
	}

};

int main(){
	MiddleCode m;
	cout<<m.encode("word")<<endl;
	cout<<m.encode("aaaaa")<<endl;
	cout<<m.encode("abacaba")<<endl;
	cout<<m.encode("shjegr")<<endl;
	cout<<m.encode("adafaaaadafawafwfasdaa")<<endl;
}