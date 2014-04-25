// author : raghuram2404
// math (logic got from editorials of this problem)
// accepted for 224.82 points

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename t> t GCD(t a,t b){	
  t c;
  while ( a != 0 ){
     c = a; a = b%a;  b = c;
  }
  return b;
}

ll LCM(ll a, ll b){
	return (ll)(a/GCD<ll>(a,b)*b);
}

class LCMSetEasy{
public:
	string include (vector<int> v, int x){
		//remove all the elements which will not divide x
		//got this strategy from topcoder editorials
		ll lcm = 1;
		for(int i=0; i<v.length(); i++){
			if(x%v[i]==0){
				lcm = LCM(lcm, v[i]);
			}
			if(lcm > x) return "Impossible";
		}
		if(lcm == x) return "Possible";
		else return "Impossible";
	}
};