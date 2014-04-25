// author : raghuram2404
// sorting, ad-hoc
// accepted for 206.66 points


#include <bits/stdc++.h>
using namespace std;

class WinterAndMandarins{
	public:
		int getNumber(vector<int> v, int k){
			int n = v.size();
			sort(v.begin(), v.end());
			int diff = INT_MAX;
			for(int i=0; i<=n-k; i++){
				// compare i to i+k
				int d = v[i+k-1] - v[i];
				if(diff == INT_MAX) diff = d;
				else if(diff > d) diff = d;
			}
			return diff;
		}
};

