#include <bits/stdc++.h>
using namespace std;

class BracketExpressions{
	public: 
		string ifPossible(string expression){
			int i=0, len = expression.length();
			int count1 = 0,count2 = 0,count3 = 0,count4 = 0;
			for(i=0; i<len; i++){
				switch(expression[i]){
					case '[': count1++; count4++; break;
					case '{': count2++; count4++; break;
					case '(': count3++; count4++; break;
					case ']': count1--; count4--; break;
					case '}': count2--; count4--; break;
					case ')': count3--; count4--; break;
					default : count4++;;
				}
			}
			//cout<<count1<<" "<<count2<<" "<<count3<<" "<<count4<<" "<<expression<<endl;
			if(count4==0){
				if(count1==0 && count2==0 && count3==0) return "possible";
				else return "impossible";
			}
			if(abs(count1+count2+count3) == count4) return "possible";
			return "impossible";
		}
};

int main(){
	BracketExpressions e;
	cout<<e.ifPossible("([]X()[()]XX}[])X{{}}]")<<endl;
}