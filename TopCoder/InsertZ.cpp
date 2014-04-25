// author : raghuram2404
// string and ieration
// accepted for 194.20 points

#include <bits/stdc++.h>
using namespace std;

class InsertZ{
	public:
		string canTransform(string init, string goal){
			bool zfound = true;
			while(zfound){
				zfound = false;
				int n = goal.size();
				for(int i=0; i<n; i++){
					if(goal[i] == 'z'){
						goal.erase(i,1);
						zfound = true;
						break;
					}
				}
			}
			cout<<goal<<endl;
			if(init == goal)
				return "Yes";
			return "No";	
		}
};

int main(){
	InsertZ i;
	cout<<i.canTransform("fox", "fozx")<<endl;
	return 0;
}