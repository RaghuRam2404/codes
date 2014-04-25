// author : raghuram2404
// 
// accepted for

#include <bits/stdc++.h>
using namespace std;

class TheMatrix{
public:
	int MaxArea(vector<string> v){
		int maxArea = 0;
		for(int i=0; i<v.size(); i++){
			for(int j=0; j<v[0].size(); j++){
				int length = 1, breadth = 1;
				for(int k=i; k<v.size(); k++){
					for(int l=j; l<v[0].size(); l++){
						if(k==i && l==j);
						else if(k==i){
							if(v[k][j] == v[k][j-1])
						}
					}
				}
			}
		}
		return maxArea;			
	}
};

int main(){

	return 0;
}