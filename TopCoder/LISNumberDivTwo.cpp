// author : raghuram2404
// ad-hoc
// accepted for 245.20 points

#include <bits/stdc++.h>
using namespace std;

class LISNumberDivTwo{
public:
	int calculate(vector <int> seq){
		int prev = 0;
		int cnt = 1;
		for(int i=0; i<seq.size(); i++){
			if(seq[i] > prev);
			else if(seq[i] <= prev){
				cnt ++;
			}prev = seq[i];
		}
		return cnt;
	}
};

int main(){

	return 0;
}