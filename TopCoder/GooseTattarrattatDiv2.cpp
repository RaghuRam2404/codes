// author : raghuram2404
// greedy, simple iteration and search
// accepted for 241.69 points

#include <bits/stdc++.h>
using namespace std;

class GooseTattarrattatDiv2{
	public:
		int getmin(string s){
			int n = s.size();
			int cnt[26] = {0};
			int maxIn = -1;
			for(int i=0; i<n; i++){
				cnt[s[i]-'a'] ++;
			}
			for(int i=0; i<26; i++){
				if(maxIn < cnt[i])
					maxIn = cnt[i];
			}
			return total-maxIn;
		}
};

int main(){

	return 0;
}