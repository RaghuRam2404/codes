// author : raghuram2404
// simple search and iteration
// accepted for 149.06 points

#include <bits/stdc++.h>
using namespace std;

class TeamsSelection{
	public:
		string simulate(vector <int> preference1, vector <int> preference2){
			bool taken[55] = {false};
			string s;
			for(int i=0; i<preference1.size(); i++)
				s += "0";
			int ptr1 = 0, ptr2 = 0;
			for(int i=0; i<preference1.size(); i++){
				if(i%2 == 0){
					// player 1 turn
					if(taken[preference1[ptr1]] == false){
						taken[preference1[ptr1]] = true,
						s[preference1[ptr1]-1] = '1';
						ptr1++;
					}else{
						while(taken[preference1[ptr1]] == true){
							ptr1++;
						}
						taken[preference1[ptr1]] = true,
						s[preference1[ptr1]-1] = '1';
						ptr1++;
					}
				}else{
					// player 2 turn
					if(taken[preference2[ptr2]] == false){
						taken[preference2[ptr2]] = true,
						s[preference2[ptr2]-1] = '2';
						ptr2++;
					}else{
						while(taken[preference2[ptr2]] == true){
							ptr2++;
						}
						taken[preference2[ptr2]] = true,
						s[preference2[ptr2]-1] = '2';
						ptr2++;
					}

				}
			}
			return s;
		}
};

int main(){
	TeamsSelection t;
	std::vector<int> v1,v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	cout<<t.simulate(v1, v2)<<endl;
	return 0;
}