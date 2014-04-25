// author : raghuram2404
// greedy
// accepted for 244.27 points

#include <bits/stdc++.h>
using namespace std;

class LittleElephantAndBooks{
	public:
		int getNumber(vector <int> pages, int number){
			sort(pages.begin(), pages.end());
			int num = 0, i=0;
			for(i=0; i<number-1; i++)
				num += pages[i];
			num += pages[i+1];
			return num;
		}
};

int main(){

	return 0;
}