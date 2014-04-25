// author : raghuram2404
// maths ad-hoc
// accepted for 197.26 points

#include <bits/stdc++.h>
using namespace std;


template<typename t> t gcd(t a,t b){	
  t c;
  while ( a != 0 ){
     c = a; a = b%a;  b = c;
  }
  return b;
}

class FoxAndClassroom{
	public:
		string ableTo(int n, int m){
			if(n<m){
				int t = n;
				n = m;
				m = t;
			}
			if((n%2 == 0) && (m%2 == 0)) return "Impossible";
			if(n%m == 0) return "Impossible";
			if(gcd(n,m) != 1) return "Impossible";
			else return "Possible";
		}
};


int main(){

	return 0;
}