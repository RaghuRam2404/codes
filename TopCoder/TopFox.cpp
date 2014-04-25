// author : raghuram2404
// brute force, string manipulation
// accepted for 228.79 points 

#include <bits/stdc++.h>
using namespace std;

class TopFox{
	vector<string> names;
public:

	bool contains(string a){
		for(int i=0; i<names.size(); i++)
			if(names[i] == a)
				return true;
		return false;
	}

	int possibleHandles(string a, string b){
		names.clear();
		int alen = a.size(), blen = b.size();
		for(int i=0; i<alen; i++){
			for(int j=0; j<blen; j++){
				string aa = a.substr(0,i+1);
				string bb = b.substr(0,j+1);
				if(!contains(aa+bb))
					names.push_back(aa+bb);

			}
		}
		return names.size();
	}
};

int main(){

	return 0;
}