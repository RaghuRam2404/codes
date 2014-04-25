// author : raghuram2404
// brute force
// accepted for 230.31 points

#include <bits/stdc++.h>
using namespace std;

class TaroString{
	public:
		string getAnswer(string s){
			int n = s.size();
			int c=0, a=0, t=0;
			int cpos=-1, apos=-1, tpos=-1;
			for(int i=0; i<n; i++){
				if(s[i] == 'C') c++, cpos=i;
				else if(s[i] == 'A') a++, apos=i;
				else if(s[i] == 'T') t++, tpos=i;
			}
			if(c==1 && a==1 && t==1 && (cpos < apos && apos < tpos))
				return "Possible";
			else
				return "Impossible";
		}
};