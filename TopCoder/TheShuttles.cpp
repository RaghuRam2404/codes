// author : raghuram2404
// Simple Search, Iteration
// accepted for 142.55 points

#include <bits/stdc++.h>
using namespace std;

class TheShuttles{
	public:
		int getLeastCost(vector<int> v, int base, int seat){
			int max = -1;
			for(int i=0; i<v.size(); i++)
				if(max < v[i]) max = v[i];
			//cout<<max<<"-->";
			int n = v.size();
			int cost = INT_MAX;
			for(int i=1; i<=max; i++){
				int basecost = base + seat*i;
				int currcost, num=0;
				for(int j=0; j<n; j++){
					num += (ceil((double)v[j]/i));
				}
				currcost = basecost * num;
				//cout<<i<<" "<<num<<" "<<currcost<<endl;
				if(currcost < cost) cost = currcost;
			}
			return cost;
		}
};

int main(){

	TheShuttles t;
	std::vector<int> v;
	v.push_back(9);
	cout<<t.getLeastCost(v, 30, 5)<<endl;
	v.clear();
	v.push_back(9);
	v.push_back(4);
	cout<<t.getLeastCost(v, 10, 5)<<endl;
	// 51, 1, 77, 14, 17, 10, 80
	v.clear();
	v.push_back(51);
	v.push_back(1);
	v.push_back(77);
	v.push_back(14);
	v.push_back(17);
	v.push_back(10);
	v.push_back(80);
	cout<<t.getLeastCost(v, 32, 40)<<endl;
}