// author : raghuram2404
// math ad-hoc
// accepted for 161.48 points

#include <bits/stdc++.h>
using namespace std;


class  LittleElephantAndDouble{
public:
	string getAnswer(std::vector<int> v){
		int n = v.size();
		int min = INT_MAX;
		for(int i=0; i<n; i++)
			if(v[i] < min)
				min = v[i];
		bool ans = true;
		for(int i=0; i<n; i++){
			int quo = v[i]/min;
			int rem = v[i]%min;
			if((quo&(quo-1))!=0 || rem != 0) ans = false;
		}
		return (ans)?"YES":"NO";
	}
};
