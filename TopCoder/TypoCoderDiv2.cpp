// author : raghuram2404
// brute force, ad-hoc
// accepted for 223.59 points
#include <bits/stdc++.h>
using namespace std;

class TypoCoderDiv2{
	public:
	
		int count(vector<int> r){
			int c = 0;
			bool color=0;	// 0 ciel and 1 brown
			for(int i=0; i<r.size(); i++){
				if(r[i] >= 1200){
					if(color==0)c++, color=1; 
				}else{
					if(color==1) c++, color=0;
				}				
			}
			return c;
		}
};


int main(){

	TypoCoderDiv2 t;
	vector<int> v;
	v.push_back(1000);
	v.push_back(1200);
	v.push_back(1199);
	cout<<t.count(v)<<endl;
	v.clear();
	v.push_back(1500);
	v.push_back(2200);
	v.push_back(900);
	v.push_back(3000);
	cout<<t.count(v)<<endl;
}