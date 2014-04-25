// author : raghuram2404
// simple search and iteration
// accepted for 234.84 points

#include <bits/stdc++.h>
using namespace std;

class KeyDungeonDiv2{
public:
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys){
		int doors = 0;
		int n = doorG.size();
		int red = keys[0], green = keys[1], white = keys[2];
		for(int i=0; i<n; i++){
			if(doorR[i] > red) white -= (doorR[i] - red);
			if(doorG[i] > green) white -= (doorG[i] - green);
			if(white >= 0) doors ++;
			white = keys[2];
		}
		return doors;
	}
};

int main(){
	
	return 0;
}