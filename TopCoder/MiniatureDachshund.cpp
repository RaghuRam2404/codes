// author : raghuram2404
// greedy
// accepted for 173.02 points
#include <bits/stdc++.h>
using namespace std;

class MiniatureDachshund{
public:

	int maxMikan(vector<int> mikan, int wt){
		int n = mikan.size(), ans=0;
		sort(mikan.begin(), mikan.end());
		for(int i=0; i<n; i++){
			if(mikan[i]+wt <= 5000){
				ans++;
				wt += mikan[i];
			}
		}
		return ans;
	}
};

int main(){

	return 0;
}