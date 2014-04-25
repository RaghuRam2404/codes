// author : raghuram2404
// brute force
// accepted for 230.86 points

#include <bits/stdc++.h>
using namespace std;

class LittleElephantAndBallsAgain{
	public:
		int getNumber(string s){
			int n = s.size();
			// find max length
			char a;
			int maxLength = 1, length=1;
			a = s[0];
			for(int i=1; i<n; i++){
				if(s[i] == a){
					length ++;
					if(maxLength < length) maxLength = length;
				}else{
					a = s[i];
					length = 1;
				}
			}return n-maxLength;
		}
};

int main(){

	LittleElephantAndBallsAgain l;
	cout<<l.getNumber("RRGGBB")<<endl;
	cout<<l.getNumber("R")<<endl;
	cout<<l.getNumber("RGGGBB")<<endl;
	cout<<l.getNumber("RGBRBRGRGRBBBGRBRBRGBGBBBGRGBBBBRGBGRRGGRRRGRBBBBR")<<endl;
	return 0;
}