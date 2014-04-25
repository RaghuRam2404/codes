// author : raghuram2404
// Brute force , string
// accepted for 233.62 points

#include <bits/stdc++.h>
using namespace std;

class RaiseThisBarn{
	public:
		int calc(string s){
			int n = s.size(), cnt=0;
			for(int i=0; i<n; i++) if(s[i] == 'c') cnt ++;
			if(cnt == 0) return n-1;	
			if(cnt%2 != 0) return 0;
			int pcnt = 0, dcnt=0;
			bool found = false;
			for(int i=0; i<n; i++){
				if(found){
					if(s[i] == 'c') break;
					else dcnt++;
				}else{
					if(s[i] == 'c')
						pcnt ++;

					if(pcnt == cnt/2) found = true;
				}
			}
			return dcnt+1;
		}
};

int main(){

	return 0;
}