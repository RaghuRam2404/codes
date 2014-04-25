#include <bits/stdc++.h>
using namespace std;

class FoxAndWord{
	public:
	int howManyPairs(vector<string> in){
		int n = in.size(), ans=0;
		string a,b;
		for (int i=0; i<n-1; i++){
			a = in[i];
			for(int j=i+1; j<n; j++){
				b = in[j];
				// compare a,b
				if(a == b){
					ans++;
					continue;
				}
				if(a.size() == b.size()){
					int s = a.size();
					for(int k=1; k<=a.size()-1; k++){
						// first size is from 0 to k
						// and k+1 to n
						string a1 = a.substr(0,k);
						string a2 = a.substr(k,s-k);
						if(a1+a2 == b || a2+a1 == b){
							ans ++; break;
						}
					}
				}
				
			}
		}
		return ans;
	}
};



int main(){
	vector<string> in;
	string a = "tokyo", b = "kyoto";
	in.push_back(a);
	in.push_back(b);
	FoxAndWord f;
	cout<<f.howManyPairs(in)<<endl;
}
