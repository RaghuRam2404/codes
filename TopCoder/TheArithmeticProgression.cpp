// author : raghuram2404
// math ad-hoc
// accepted for 183.90 points

#include <bits/stdc++.h>
using namespace std;

class TheArithmeticProgression{
	public:
		double minimumChange(int a, int b, int c){
			double d1 = INT_MAX, d2 = INT_MAX, d3 = INT_MAX;

			double r = b-a;
			if(c == b+r) return 0.0f;

			// a,b are in ap
			r = b-a;
			d1 = abs(c-(a+2*r));
			cout<<"("<<r<<" "<<d1<<") ";
			// a,c are in ap
			r = ((double)c-(double)a)/2;
			d2 = abs(b-(a+r));
			cout<<"("<<r<<" "<<d2<<") ";
			// b,c are in ap
			r = c-b;
			d3 = abs(a-(b-r));
			cout<<"("<<r<<" "<<d3<<") ";
			return min(d1, min(d2,d3));
		}
};

int main(){
	TheArithmeticProgression t;
	cout<<t.minimumChange(0,2,1)<<endl;
	cout<<t.minimumChange(3,2,1)<<endl;
	cout<<t.minimumChange(4,4,8)<<endl;
	return 0;
}
