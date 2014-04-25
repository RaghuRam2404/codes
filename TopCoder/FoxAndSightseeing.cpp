// author : raghuram2404
// ad-hoc Simple Search, Iteration
// accepted for 151.90 points

#include <bits/stdc++.h>
using namespace std;

class FoxAndSightseeing{
	public:
		int getDist(int a, int b){
			return abs(a-b);
		}
		int getMin(std::vector<int> v){
			int n = v.size();
			//cout<<"SIZE : "<<n<<endl;
			int min = INT_MAX;
			for(int j=1; j<=n-2; j++){
				// skip jth city
				//cout<<"SKIP "<<j<<" ";
				int dist = 0;
				for(int i=0; i<n-1; i++){
					if(j==i+1){
						//cout<<"("<<v[i]<<","<<v[i+2]<<")";
						dist += getDist(v[i], v[i+2]);
					}else if(i != j){
						//cout<<"("<<v[i]<<","<<v[i+1]<<")";
						dist += getDist(v[i], v[i+1]);					
					}
				}
				//cout<<dist<<endl;
				if(min > dist)
					min = dist;
			}
			return min;
		}

};

int main(){
	FoxAndSightseeing f;
	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(3);
	cout<<f.getMin(v)<<endl;
	v.clear();
	v.push_back(-2);
	v.push_back(4);
	v.push_back(3);
	cout<<f.getMin(v)<<endl;
	return 0;
}